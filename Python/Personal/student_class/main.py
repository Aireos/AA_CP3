# AKA Student Class

#defining the class for all the student info & parts
class Student:
    def __init__(self,id=0,name="John Doe",grade = 100):
        self.id = f"{id:03d}"
        self.name = name
        self.grade = grade
    #returns the grade of the user
    def get_grade(self):
        return self.grade
    #sets the grade of the user
    def set_grade(self, grade):
        self.grade = grade
    #returns a string with all of the info for 
    def __str__(self):
        return f"ID: {self.id}, Name: {self.name}, Grade: {self.grade}"
#setting orignal student values
billy=Student(1,"Billy Bob",85)
snap=Student(2,"Snap Crackle",76)
pop=Student(3,"Pop Snap",66)
crackle=Student(4,"Crackle Pop",58)
bob=Student(5,"Bob Billy",49)
#printing origanal student info
print()
print("Initial student information:")
print(billy)
print(snap)
print(pop)
print(crackle)
print(bob)
print(Student())
print()
#re-setting the grade for 3 students
bob.set_grade(21)
billy.set_grade(13)
snap.set_grade(3)
#printing the reset grades
print("Updated student information:")
print(f"Bob Billy's new grade: {bob.get_grade()}")
print(f"Billy Bob's new grade: {billy.get_grade()}")
print(f"Snap Crackle's new grade: {snap.get_grade()}")
print()
