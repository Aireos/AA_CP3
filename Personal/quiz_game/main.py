#Alex Anderson, Quiz Game
titles = ["","",""]
qa = [[["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0]],[["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0]],[["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0],["",0]]]

#import high score

def question_list_choice(qa,titles):
    number = -1
    for i in titles:
        number+=1
        print(f"{number}. {i}")
    while True:
        try:
            choice = int(input("What number do you want to do?: "))
            break
        except:
            continue
    number = -1
    for i in titles:
        number += 1
        if number == choice:
            return qa[number]
        
def questionair(qa_list):
    score = 0
    for i in qa_list:
        question = i[0]
        answer = i[1]
        print(question)
        while True:
            try:
                choice = int(input("answer: "))
                break
            except:
                continue
        if choice == answer:
            score += 1
            print("You got it!")
        else:
            print("Better luck next time!")
    print(f"You're score was:{score}")
    return score

def main(high_score):
    print("1. quizzing\n2. quiz maker\n3. login\n4. exit")
    while True:
        try:
            choice = int(input("What number do you want to do?: "))
            break
        except:
            continue
    if choice == 1:
        qa_list = question_list_choice(qa,titles)
        current_score = questionair(qa_list)
        if current_score > high_score:
            high_score = current_score
    if choice == 2:
        print("sorry, this has not been made yet!")
    if choice == 3:
        print("sorry, this has not been made yet!")
    if choice == 4:
        #update high score
        return