# AKA Student Class

class Student:
    def __init__(self,id=0,name="John Doe",grade = 100):
        self.id = id
        self.name = name
        self.grade = grade
    def get_grade(self):
        return self.grade
    def set_grade(self, grade):
        self.grade = grade
    def __str__(self):
        return f"ID: {self.id}, Name: {self.name}, Grade: {self.grade}"

billy=Student(0o01,"Billy Bob",85)
snap=Student(0o02,"Snap Crackle",76)
pop=Student(0o03,"Pop Snap",66)
crackle=Student(0o04,"Crackle Pop",58)
bob=Student(0o05,"Bob Billy",49)
print()
print("Initial student information:")
print(billy)
print(snap)
print(pop)
print(crackle)
print(bob)
print(Student())
print()
bob.set_grade(21)
billy.set_grade(13)
snap.set_grade(3)
print("Updated student information:")
print(f"Bob Billy's new grade: {bob.get_grade()}")
print(f"Billy Bob's new grade: {billy.get_grade()}")
print(f"Snap Crackle's new grade: {snap.get_grade()}")
print()