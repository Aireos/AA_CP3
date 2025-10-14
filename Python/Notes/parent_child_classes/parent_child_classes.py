# AKA 

class Animal():

    def __init__(self, age, color):
        self.age = age
        self.color = color

    def move(self):
        pass

    def __str__(self):
        return(f"Age: {self.age}\nColor: {self.color}")
    
    def __eq__(self, other):
        return (self.age == other.age and self.color == other.color)
    
class Dog(Animal):

    def __init__(self,age,color,owner,breed,name):
        super().__init__(age,color)
        self.owner = owner
        self.breed = breed
        self.name = name

    def __str__(self):
        return f"Name:{self.name}\nBreed:{self.breed}\nOwner:{self.owner}\nColor:{self.color}\nAge:{self.age}"
    
    def move(self):
        print(f"{self.name} runs")
    
    def __eq__(self, other):
        return (
            self.age == other.age and 
            self.color == other.color and
            self.owner == other.owner and
            self.breed == other.breed and
            self.name == other.name)


bobby = Dog(5, "brown", "Jill", "Bulldog", "Bobby")
birdy = Dog(5, "brown", "Jill", "Bulldog", "Birdy")
alex = Animal(16,"white")
nick = Animal(15, "white")
print(bobby)
print(birdy)
print(alex)
print(nick)

# What is a parent/abstract class?
# a class that defines parts for child classes

# How do you create a child class?
# class Child(Parent):

# How does a child class inherit from the parent class?
# super().__init__(age,color)

# What are class diagrams?
# a diagram that shows the connections between the parent and child classes

# How are class diagrams used to show a parent/child relationship?
# by drawing arrows to show the connections

# How do you overload operators in a class?
# def __str__(self):
#    return super().__str__()

# What are test cases?
# same folder, seperate file

# Why do we use test cases?
# 

# How do we create test cases?
# test_filename.py
# filename_test.py