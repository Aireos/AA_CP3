#Alex Anderson, Quiz Game
import random

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

def login(users, current_user):
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
                if admin == "yes":
                    admins.append(username)
                users.append([username, password, 0])
                current_user = username
                print(f"User {current_user} registered and logged in successfully!")
                return users, current_user
            else:
                print("Login failed. Returning to main menu.")
                return users, current_user

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
                choice = int(input("answer: "))
                break
            except:
                print("That was not an option!")
                continue
        if choice == answer_option:
            score += 1
            print("You got it!")
        else:
            print("Better luck next time!")
    print(f"You're score was: {score}")
    return score

def main():
    titles = ["United States History","Science","Literature"]
    qa = [[["Who was the first president of the United States?","George Washington","Abraham Lincoln"],["In what year did the American Revolution end?","1783","1776"],["What document was signed in 1776 to declare independence from Great Britain?","Declaration of Independence","The Constitution"],["Who wrote the Declaration of Independence?","Thomas Jefferson","John Adams"],["What was the name of the ship the Pilgrims sailed to America on?","Mayflower","Santa Maria"],["What major event occurred on December 7, 1941?","Attack on Pearl Harbor","D-Day Invasion"],["Which war was fought between the North and South in the United States?","Civil War","Revolutionary War"],["Who was a leader of the Civil Rights Movement?","Martin Luther King Jr.","Malcolm X"],["What is the name of the famous speech given by Martin Luther King Jr.?","I Have a Dream","The Gettysburg Address"],["Which president was responsible for the Louisiana Purchase?","Thomas Jefferson","Andrew Jackson"],["What year did the United States enter World War I?","1917","1914"],["Who was the president during the Great Depression and World War II?","Franklin D. Roosevelt","Herbert Hoover"],["What was the name of the program that provided aid to Western Europe after World War II?","Marshall Plan","New Deal"],["Which state was the last to join the United States?","Hawaii","Alaska"],["What is the name of the first ten amendments to the Constitution?","Bill of Rights","Articles of Confederation"],["Which president signed the Emancipation Proclamation?","Abraham Lincoln","Ulysses S. Grant"],["What year did the Berlin Wall fall?","1989","1991"],["What is the name of the first permanent English settlement in North America?","Jamestown","Plymouth"],["Which war was fought between the United States and Vietnam?","Vietnam War","Korean War"],["Who was the first woman to fly solo across the Atlantic Ocean?","Amelia Earhart","Sally Ride"],["What year did humans first walk on the moon?","1969","1957"],["What was the name of the ship that sank after hitting an iceberg?","Titanic","Lusitania"],["Who was the president during the Cuban Missile Crisis?","John F. Kennedy","Lyndon B. Johnson"],["What famous landmark was a gift from France to the United States?","Statue of Liberty","Eiffel Tower"],["What was the name of the first successful steamboat?","Clermont","Savannah"],["What year did the United States purchase Alaska from Russia?","1867","1803"],["Who was the commander of the Continental Army during the American Revolution?","George Washington","Benjamin Franklin"],["What was the main cause of the War of 1812?","Maritime rights violations","Territorial disputes"],["Who was the first person to circumnavigate the globe?","Ferdinand Magellan","Christopher Columbus"],["What was the name of the treaty that ended the Mexican-American War?","Treaty of Guadalupe Hidalgo","Treaty of Paris"],["What was the name of the movement to end slavery?","Abolitionist Movement","Suffrage Movement"],["Which president was assassinated in 1865?","Abraham Lincoln","James A. Garfield"],["What was the name of the expedition that explored the Louisiana Purchase?","Lewis and Clark Expedition","Zebulon Pike Expedition"],["What year did women in the United States get the right to vote?","1920","1919"],["Who was the first woman to be appointed to the Supreme Court?","Sandra Day O'Connor","Ruth Bader Ginsburg"],["What year did the Great Chicago Fire occur?","1871","1906"],["What was the name of the conflict between the United States and Spain in 1898?","Spanish-American War","Philippine-American War"],["Who was the first African American baseball player in Major League Baseball?","Jackie Robinson","Babe Ruth"],["What year did the stock market crash that started the Great Depression?","1929","1930"],["Who was the famous gangster from the Prohibition era?","Al Capone","John Dillinger"],["What was the name of the naval base attacked by Japan in World War II?","Pearl Harbor","Midway"],["Which president was responsible for the creation of the Interstate Highway System?","Dwight D. Eisenhower","Harry S. Truman"],["What year did the Korean War begin?","1950","1945"],["Who was the first person to walk on the moon?","Neil Armstrong","Buzz Aldrin"],["What was the name of the scandal that led to President Nixon's resignation?","Watergate","Teapot Dome"],["What year was the Constitution of the United States ratified?","1788","1776"],["Who was the famous outlaw of the American West?","Billy the Kid","Jesse James"],["What was the name of the treaty that ended World War I?","Treaty of Versailles","Treaty of Paris"],["Which state was the first to ratify the Constitution?","Delaware","Pennsylvania"],["Who was the author of the 'Common Sense' pamphlet?","Thomas Paine","Benjamin Franklin"]],[["What is the study of living organisms called?","Biology","Geology"],["What is the chemical symbol for water?","H2O","CO2"],["What is the largest planet in our solar system?","Jupiter","Saturn"],["What is the main gas that makes up the Earth's atmosphere?","Nitrogen","Oxygen"],["What is the process by which plants make their own food?","Photosynthesis","Respiration"],["What is the hardest natural substance on Earth?","Diamond","Graphite"],["What is the name of the force that keeps us on the ground?","Gravity","Magnetism"],["What is the speed of light in a vacuum?","299,792,458 meters per second","300,000,000 meters per second"],["What is the chemical symbol for gold?","Au","Ag"],["What is the name of the process where a liquid turns into a gas?","Evaporation","Condensation"],["What is the largest organ in the human body?","Skin","Liver"],["What is the center of an atom called?","Nucleus","Proton"],["What is the name of the galaxy our solar system is in?","Milky Way","Andromeda"],["What is the name of the part of the eye that controls the size of the pupil?","Iris","Cornea"],["What is the boiling point of water in Celsius?","100°C","0°C"],["What is the name of the instrument used to measure earthquakes?","Seismograph","Barometer"],["What is the name of the protective layer around the Earth that absorbs ultraviolet radiation?","Ozone layer","Ionosphere"],["What is the name of the chemical that gives plants their green color?","Chlorophyll","Carotenoid"],["What is the name of the smallest bone in the human body?","Stapes","Femur"],["What is the name of the process where a solid turns directly into a gas?","Sublimation","Melting"],["What is the unit of measurement for electrical resistance?","Ohm","Volt"],["What is the name of the chemical element with the symbol 'Fe'?","Iron","Gold"],["What is the name of the largest ocean on Earth?","Pacific Ocean","Atlantic Ocean"],["What is the name of the planet closest to the sun?","Mercury","Venus"],["What is the name of the study of the Earth's physical structure and substance?","Geology","Biology"],["What is the name of the gas that humans exhale?","Carbon dioxide","Oxygen"],["What is the name of the phenomenon where light bends as it passes through a medium?","Refraction","Reflection"],["What is the name of the largest volcano in the solar system?","Olympus Mons","Mauna Loa"],["What is the name of the chemical process that releases energy from food?","Metabolism","Digestion"],["What is the name of the theory of how the universe began?","Big Bang Theory","Steady State Theory"],["What is the name of the largest moon of Saturn?","Titan","Europa"],["What is the name of the process that powers the sun?","Nuclear fusion","Nuclear fission"],["What is the name of the instrument used to see very small objects?","Microscope","Telescope"],["What is the name of the outermost layer of the Earth?","Crust","Mantle"],["What is the name of the star at the center of our solar system?","Sun","Sirius"],["What is the name of the type of rock formed from cooled lava or magma?","Igneous","Sedimentary"],["What is the name of the field of study that deals with matter and energy?","Physics","Chemistry"],["What is the name of the process of a liquid turning into a solid?","Freezing","Melting"],["What is the name of the part of the brain responsible for balance and coordination?","Cerebellum","Cerebrum"],["What is the name of the largest land animal?","African bush elephant","Giraffe"],["What is the name of the largest bone in the human body?","Femur","Stapes"],["What is the name of the gas that makes up most of the air we breathe?","Nitrogen","Oxygen"],["What is the name of the element with the symbol 'O'?","Oxygen","Gold"],["What is the name of the study of the stars and planets?","Astronomy","Astrology"],["What is the name of the first successful cloning of a mammal?","Dolly the sheep","Snuppy the dog"],["What is the name of the famous law of motion formulated by Isaac Newton?","Newton's First Law","Einstein's Theory of Relativity"],["What is the name of the process of turning light energy into chemical energy?","Photosynthesis","Respiration"],["What is the name of the force that attracts two masses to each other?","Gravity","Magnetism"],["What is the name of the unit of measurement for force?","Newton","Joule"],["What is the name of the process of a gas turning into a liquid?","Condensation","Evaporation"]],[["Who wrote the play 'Romeo and Juliet'?","William Shakespeare","Charles Dickens"],["What is the name of the famous detective created by Arthur Conan Doyle?","Sherlock Holmes","Hercule Poirot"],["Who wrote the novel '1984'?","George Orwell","Aldous Huxley"],["What is the name of the hobbit who carries the One Ring in 'The Lord of the Rings'?","Frodo Baggins","Bilbo Baggins"],["Who is the author of 'To Kill a Mockingbird'?","Harper Lee","J.D. Salinger"],["What is the name of the famous ship in Herman Melville's 'Moby-Dick'?","Pequod","Hispaniola"],["Who wrote 'The Great Gatsby'?","F. Scott Fitzgerald","Ernest Hemingway"],["What is the name of the magical school in the 'Harry Potter' series?","Hogwarts School of Witchcraft and Wizardry","Beauxbatons Academy of Magic"],["What is the name of the main character in Jane Austen's 'Pride and Prejudice'?","Elizabeth Bennet","Jane Eyre"],["Who wrote the 'Odyssey' and 'Iliad'?","Homer","Virgil"],["What is the name of the talking lion in C.S. Lewis's 'The Chronicles of Narnia'?","Aslan","Mufasa"],["Who wrote the 'Adventures of Tom Sawyer'?","Mark Twain","Herman Melville"],["What is the name of the protagonist in Fyodor Dostoevsky's 'Crime and Punishment'?","Raskolnikov","Prince Myshkin"],["Who wrote 'One Hundred Years of Solitude'?","Gabriel Garcia Marquez","Jorge Luis Borges"],["What is the name of the family in Shakespeare's 'Hamlet'?","The Danes","The Montagues"],["Who is the author of 'Frankenstein'?","Mary Shelley","Bram Stoker"],["What is the name of the protagonist in J.R.R. Tolkien's 'The Hobbit'?","Bilbo Baggins","Frodo Baggins"],["Who wrote 'Don Quixote'?","Miguel de Cervantes","Lope de Vega"],["What is the name of the famous ghost in Shakespeare's 'Macbeth'?","Banquo's ghost","The Ghost of Christmas Past"],["Who wrote 'War and Peace'?","Leo Tolstoy","Fyodor Dostoevsky"],["What is the name of the fictional town in 'To Kill a Mockingbird'?","Maycomb","Macondo"],["Who is the author of 'Wuthering Heights'?","Emily Brontë","Charlotte Brontë"],["What is the name of the famous white whale in 'Moby-Dick'?","Moby Dick","Shamu"],["Who wrote 'The Catcher in the Rye'?","J.D. Salinger","John Steinbeck"],["What is the name of the protagonist in Charles Dickens's 'Oliver Twist'?","Oliver Twist","David Copperfield"],["Who wrote 'Les Misérables'?","Victor Hugo","Alexandre Dumas"],["What is the name of the famous island in 'The Count of Monte Cristo'?","Isle of If","Treasure Island"],["Who is the author of 'Dracula'?","Bram Stoker","Mary Shelley"],["What is the name of the famous detective in Agatha Christie's novels?","Hercule Poirot","Sherlock Holmes"],["Who wrote 'The Picture of Dorian Gray'?","Oscar Wilde","Robert Louis Stevenson"],["What is the name of the protagonist in Charlotte Brontë's 'Jane Eyre'?","Jane Eyre","Elizabeth Bennet"],["Who wrote 'The Divine Comedy'?","Dante Alighieri","Virgil"],["What is the name of the protagonist in Vladimir Nabokov's 'Lolita'?","Humbert Humbert","Stanley Kowalski"],["Who wrote 'The Metamorphosis'?","Franz Kafka","Albert Camus"],["What is the name of the famous horse in 'Don Quixote'?","Rocinante","Shadowfax"],["Who is the author of 'The Little Prince'?","Antoine de Saint-Exupéry","Hermann Hesse"],["What is the name of the protagonist in George Orwell's 'Animal Farm'?","Napoleon","Snowball"],["Who wrote 'Alice's Adventures in Wonderland'?","Lewis Carroll","Beatrix Potter"],["What is the name of the famous wizard in J.R.R. Tolkien's 'The Lord of the Rings'?","Gandalf","Merlin"],["Who wrote 'Frankenstein'?","Mary Shelley","Bram Stoker"],["What is the name of the famous ghost in Shakespeare's 'Macbeth'?","Banquo's ghost","The Ghost of Christmas Past"],["Who wrote 'War and Peace'?","Leo Tolstoy","Fyodor Dostoevsky"],["What is the name of the fictional town in 'To Kill a Mockingbird'?","Maycomb","Macondo"],["Who is the author of 'Wuthering Heights'?","Emily Brontë","Charlotte Brontë"],["What is the name of the famous white whale in 'Moby-Dick'?","Moby Dick","Shamu"],["Who wrote 'The Catcher in the Rye'?","J.D. Salinger","John Steinbeck"],["What is the name of the protagonist in Charles Dickens's 'Oliver Twist'?","Oliver Twist","David Copperfield"],["Who wrote 'Les Misérables'?","Victor Hugo","Alexandre Dumas"],["What is the name of the famous island in 'The Count of Monte Cristo'?","Isle of If","Treasure Island"],["Who is the author of 'Dracula'?","Bram Stoker","Mary Shelley"]]]
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
        else:
            print(f"Not logged in.")
        
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
                users, current_user = login(users, current_user)
        elif choice == 4:
            if current_user:
                print(f"Goodbye, {current_user}!")
            else:
                print("Goodbye!")
            return
        else:
            print("That was not an option!")

main()
