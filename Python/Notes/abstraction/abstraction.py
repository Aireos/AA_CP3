#AKA Abstraction Notes

from abc import *

class Animal(ABC):
    def __init__(self, name):
        self.name = name
    
    @abstractmethod
    def move(self):
        pass   

class Quadrupeds(Animal):
    def __init__(self, name):
        super().__init__(name)
    
    def move(self):
        print(f"{self.name} can walk or run.")

class Aquatic(Animal):
    def __init__(self, name):
        super().__init__(name)
    
    def move(self):
        print(f"{self.name} can swim.")

class SeaLion(Aquatic, Quadrupeds):
    def __init__(self, name):
        super().__init__(name)
    
    def eats(self):
        print(f"{self.name} eats penguins and krill.")

animal = Animal("Goose")

print(animal)

sealion = SeaLion("Greg")

print(sealion)
sealion.eats()
print(Aquatic.mro())

# Why can't you create an object from an abstract class?
# because it is made to only be used as a parent class

# How do abstract classes and abstract methods work together?
# you make a abstract class by using abstract methods

# What does abc stand for?
# abstract base class

# What are decorators? 
# start with @ symbol, used to give further info about what follows

# What is an abstract method?
# is a method written in a parent class made to be overwritten by a child class

# What is a concrete method?
# a normal method

# What is an abstract class?
# a placeholder class

# How do you make an abstract method?
# @abstractmethod
# def move(self):
#   pass  

# How can you create a class that inherits from multiple parent classes?
# class Animal(ABC,DEF)

# Why does the inheritance order matter?
# tells what method takes precedence

# What does the mro() method do when you call it on a class?
# tells you what classes you inherit from first

# What is Method resolution order?
# order of inheritance