#AKA Stacks and Queues Notes

class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None

    def peek(self):
        return self.items[-1]

    def size(self):
        return len(self.items)

class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            return None
    
    def peek(self):
        if not self.is_empty():
            return self.items[0]

    def size(self):
        return len(self.items)

# What is time complexity in programming?
# big O notation of the upper limit of time it takes a function to run

# What are the levels of time complexity?
# t = time
# n = number of values
# O(1): t = constant value / n does not affect t
# O(n): t = n / linear growth
# O(log(n)): t = log(n) / logarithmic growth
# O(n log(n)): t = n log(n) / linearithmic growth
# O(n^2): t = n^2 / quadratic growth
# O(2^n): t = 2^n / exponential growth
# O(n!): t = n! / factorial growth

# What is a stack?
# a list that you can only affect the top/last item in it

# What does LIFO stand for?
# Last In First Out

# What are the things that a stack can do?
# pop, push, peek, is_empty, size

# How are stacks normally written in python?
# defining a list with Stack name and using the methods listed above

# What is a queue?
# a list that you can only affect the front/first item in it

# How are queues different from stacks?
# stacks are LIFO, queues are FIFO