# AKA Classes and Objects

class Person:
    def __init__(self, last_name, _first_name, age, pickled_herrings):
        self._first_name = _first_name
        self.last_name = last_name
        self.age = age
        self.pickled_herrings = pickled_herrings

    def setAge(self): #setter
        self.age += 1

    def full(self): #getter
        return self._first_name + " " + self.last_name
    
    def __str__(self):
        return f"name: {self._first_name}\n {self.last_name}\n"
    
tia = Person("Tia", "Larose", 28, 5)
alextia = Person("Alex", "Anderson", 16, 21)

print(f"{tia._first_name} {tia.last_name} is {tia.age}, and they have {tia.pickled_herrings} pickled herrings!")

# What is a class?
# Abstraction of a object

# What is an object?
# A name with a value inside

# How is a class a form of encapsulation? 
# putting all the pieces together in one location

# How is a class an abstraction of an object?
# because it defines it to somthing elese

# How do you access information in an object?
# variable.type

# How do you initialize a class?
# class Person: 

# How do you set a default value 
# set a value in the definining of the variable

# How do you use type hinting?
# -> str:

# How do you set an attribute to be private?
# _name

# How do you make a class method?
# Name(all,info,in,parts)

# Why do we include docstrings?
# are just multiline commments ("""comments""")

# What does "self" do as a parameter for class methods?
# makes a basic class with all the types inside that only does it for the current instance

# What are getter and setter methods?
# gets the values 
# sets the values

# What are magic methods?
# __method_name__

# Where are class objects saved? (heap or stack?)
# heap