#Alex Anderson, Quiz Game

import random
import json
import time

def qa_export(qa):

    with open("Personal/quiz_game/qa.txt", "w") as file:
        json.dump(qa,file)


def qa_import():

    with open("Personal/quiz_game/qa.txt", "r") as file:
        qa = json.load(file)
        return qa


def stopwatch_start():
    start_time = time.time()

    with open("Personal/quiz_game/stopwatch.txt", "w") as file:
        json.dump(start_time,file)


def stopwatch_end():
    end_time = time.time()
    
    with open("Personal/quiz_game/stopwatch.txt", "r") as file:
        start_time = json.load(file)
    
    time_taken = end_time - start_time
    return int(time_taken)
    

def quiz_maker(titles, qa):
    quiz_title = input("Enter a title for your new quiz: ")
    titles.append(quiz_title)
    new_quiz = []

    while True:
        question = input("Enter a question (or type 'done' to finish): ")

        if question.lower() == 'done':
            break

        correct_answer = input("Enter the correct answer: ")
        wrong_answer = input("Enter an incorrect answer: ")
        new_quiz.append([question, correct_answer, wrong_answer])
        print("Question added!")

    qa.append(new_quiz)
    print(f"Quiz '{quiz_title}' created!")
    return titles, qa


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
                return users, current_user
            
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


def questionair(qa_list):
    score = 0
    random.shuffle(qa_list)

    for i in qa_list:
        question = i[0]
        answer = i[1]
        wrong_answer = i[2]
        print(question)

        while True:

            try:
                randomizer = random.randint(0, 1)

                if randomizer == 0:
                    print(f"1. {answer}")
                    print(f"2. {wrong_answer}")
                    answer_option = 1

                if randomizer == 1:
                    print(f"1. {wrong_answer}")
                    print(f"2. {answer}")
                    answer_option = 2

                stopwatch_start()
                choice = int(input("answer: "))

                if choice != 1 and choice != 2:
                    print("That was not an option!")
                    continue

                time_taken = stopwatch_end()
                break

            except:
                print("That was not an option!")
                continue

        if choice == answer_option:
            score += 10
            print("You got it!")

        else:
            score -= time_taken
            print("Better luck next time!")

    print(f"You're score was: {score}")
    return score


def main():
    titles = ["United States History","Science","Literature"]
    qa = qa_import()
    users = []
    admins = []
    current_user = None
    
    while True:
        if current_user:
            user_high_score = 0

            for user_entry in users:

                if user_entry[0] == current_user:
                    user_high_score = user_entry[2]
                    break

            print(f"Logged in as: {current_user} (High Score: {user_high_score})")

        print("1. quizzing\n2. quiz maker\n3. login/logout\n4. exit")

        while True:

            try:
                choice = int(input("What number do you want to do?: "))
                break

            except:
                print("That was not an option!")
                continue

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

        elif choice == 2:

            if current_user in admins:
                titles, qa = quiz_maker(titles, qa)

            else:
                print("you are not an admin!")

        elif choice == 3:

            if current_user:
                print(f"Logging out {current_user}.")
                current_user = None

            else:
                users, current_user, admins = login(users, current_user, admins)

        elif choice == 4:
            qa_export(qa)

            if current_user:
                print(f"Goodbye, {current_user}!")

            else:
                print("Goodbye!")

            return
        
        else:
            print("That was not an option!")


main()