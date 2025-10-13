'''

Needs a function
Needs to use parameters
Needs to say hi to a unique person
Needs to run x5

Best character count: 47
'''

'''
One-line for loops
Lambdas
Walrus operaors

'''

#    g=         lambda x:     print(f"Hi {x}"); [g(input()) for _ in range(5)]     #54 chars
# defines g | set x to value | prints hi & x | runs input | does 5 times |
#    g=         lambda x:      print("Hi",x)   exec("g(input())"; *5)

#print(a:=0,*[a:=a+1 for i in input()])

#g=lambda x:print("Hi",x);exec("g(input());"*5)

#exec("print("Hi", input())"*5)

def f(x):exec(f'print("Hi",{x});'*5)