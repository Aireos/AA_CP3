#Alex Anderson, Quiz Game

#importing
import random
import json
import time
import tkinter as tk


#function to export the question/answer list
def qa_export(qa):

    with open("Personal/quiz_game/qa.txt", "w") as file:
        json.dump(qa, file)


#function to import the question/answer list
def qa_import():

    with open("Personal/quiz_game/qa.txt", "r") as file:
        qa = json.load(file)
        return qa


#function to start the stopwatch
def stopwatch_start():
    start_time = time.time()

    with open("Personal/quiz_game/stopwatch.txt", "w") as file:
        json.dump(start_time, file)


#function to end the stopwatch and return the time taken
def stopwatch_end():
    end_time = time.time()

    with open("Personal/quiz_game/stopwatch.txt", "r") as file:
        start_time = json.load(file)

    time_taken = end_time - start_time
    return int(time_taken)


#function to allow admins to make quizzes
def quiz_maker(titles, qa):
    quiz_title = input("Enter a title for your new quiz: ")
    titles.append(quiz_title)
    new_quiz = []

    while True:
        question = input("Enter a question (or type 'done' to finish): ")

        if question.lower() == 'done':
            break

        correct_answer = input("Enter the correct answer: ")
        wrong_answer_1 = input("Enter an incorrect answer 1: ")
        wrong_answer_2 = input("Enter an incorrect answer 2: ")
        wrong_answer_3 = input("Enter an incorrect answer 3: ")
        new_quiz.append([question, correct_answer, wrong_answer_1, wrong_answer_2, wrong_answer_3])
        print("Question added!")

    qa.append(new_quiz)
    print(f"Quiz '{quiz_title}' created!")
    return titles, qa


#function for login and registering new users
def login(users, current_user, admins):

    while True:
        username = input("Enter username: ")
        user_found = False
        user_data = None

        for user_entry in users:
            if user_entry[0] == username:
                user_found = True
                user_data = user_entry
                break

        if user_found:
            password = input("Enter password: ")

            if user_data[1] == password:
                current_user = username
                print(f"Welcome back, {current_user}!")
                return users, current_user, admins
            
            else:
                print("Incorrect password. Please try again.")

        else:
            choice = input("User not found. Do you want to register as a new user? (y/n): ").lower()

            if choice == 'y':
                password = input("Create a password: ")
                admin = input("Type 'yes' if you are an admin: ")

                if admin.lower() == 'yes':
                    admins.append(username)
                    
                users.append([username, password, 0])
                current_user = username
                print(f"User {current_user} registered and logged in successfully!")
                return users, current_user, admins
            
            else:
                print("Login failed. Returning to main menu.")
                return users, current_user, admins


#function to choose which subject they want to be quized on
def question_list_choice(qa, titles):
    num_titles = 0

    for title in titles:
        print(f"{num_titles}. {title}")
        num_titles += 1

    while True:

        try:
            choice = int(input("What number do you want to do?: "))

            if 0 <= choice < num_titles:
                return qa[choice]
            
            else:
                print("That was not an option!")

        except:
            print("That was not an option!")
            continue


#function to show the question, posssible answers, and curent score in a tkinter interace
def show_question(question, correct_answer, all_answers, score):
    result = {'selected': None, 'correct': correct_answer}
    
    def on_answer(ans):
        result['selected'] = ans
        root.quit()

    root = tk.Tk()
    root.title("Quiz game")
    root.geometry("1000x350+200+200")
    score_label = tk.Label(root, text=f"Current Score: {score}", font=("Arial", 14))
    score_label.pack(pady=10)
    question_label = tk.Label(root, text=question, font=("Arial", 16))
    question_label.pack(pady=20)
    for answer_text in all_answers:
        button = tk.Button(root, text=answer_text, command=lambda ans=answer_text: on_answer(ans), font=("Arial", 12))
        button.pack(pady=10)
    root.mainloop()
    root.destroy()
    return result['selected']


#function that runs the tkinter interface inside it and shuffles the questions, starts and stops the stopwatch, and changes the score
def questionair(qa_list):
    score = 0
    random.shuffle(qa_list)
    for i in range(min(10, len(qa_list))):
        question_data = qa_list[i]
        question = question_data[0]
        correct_answer = question_data[1]
        wrong_answers = question_data[2:]
        all_answers = [correct_answer] + wrong_answers
        random.shuffle(all_answers)

        stopwatch_start()
        selected_answer = show_question(question, correct_answer, all_answers, score)
        if selected_answer == correct_answer:
            score += 10
        else:
            time_taken = stopwatch_end()
            score -= time_taken

    print(f"Your score was: {score}")
    return score


#function for user choices and to make the variables and pretty much just run all the other variables where they need to be ran at.
def main():
    #making variables
    titles = ["United States History", "Science", "Literature"]
    qa = qa_import()
    users = []
    admins = []
    current_user = None

    #checking if they are already loged in
    while True:
        if current_user:
            user_high_score = 0
            for user_entry in users:
                if user_entry[0] == current_user:
                    user_high_score = user_entry[2]
                    break
            print(f"Logged in as: {current_user} (High Score: {user_high_score})")

        #giving choices for what they can do
        print("1. quizzing\n2. quiz maker\n3. login/logout\n4. exit")

        while True:
            try:
                choice = int(input("What number do you want to do?: "))
                break
            except:
                print("That was not an option!")
                continue

        #opening the quizzing steps including, set choice, questionar, and new personal high score printing
        if choice == 1:
            qa_list = question_list_choice(qa, titles)
            current_score = questionair(qa_list)

            if current_user:

                for user_entry in users:

                    if user_entry[0] == current_user:

                        if current_score > user_entry[2]:
                            user_entry[2] = current_score
                            print("New personal high score!")
                            print(user_entry[2])

                        break

        #allowing acces to only admins to make quizzes
        elif choice == 2:

            if current_user in admins:
                titles, qa = quiz_maker(titles, qa)

            else:
                print("you are not an admin!")

        #logining in and out the user
        elif choice == 3:

            if current_user:
                print(f"Logging out {current_user}.")
                current_user = None

            else:
                users, current_user, admins = login(users, current_user, admins)

        #saving everything that needs to be saved and exiting the program
        elif choice == 4:
            qa_export(qa)

            if current_user:
                print(f"Goodbye, {current_user}!")

            else:
                print("Goodbye!")

            return
        
        else:
            print("That was not an option!")


#starting the program
main()