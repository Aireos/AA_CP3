# AKA

from dessert import *

def main():
    ordering = Order()
    ordering.add(Candy("Gummy Bears", 0.34, 1.25))
    ordering.add(Candy("Candy Corn", 2.45, 0.36))
    ordering.add(Cookies("Chocolate Chip", 6, 2.17))
    ordering.add(IceCream("Mint Chocolate Chip", 2, 1.66))
    ordering.add(IceCream("Cookies and Cream", 1, 1.52))
    ordering.add(Sundae("Vanilla", 2, 1.00, "Fudge", 0.33))
    for item in ordering.order:
        print(item.name)
    print(len(ordering))

main()
    