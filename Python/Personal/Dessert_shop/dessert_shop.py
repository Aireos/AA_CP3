# AKA Dessert Shop Part 1

from dessert import *
import tabulate

def main():
    ordering = Order()
    ordering.add(Candy("Candy Corn", 1.5, 0.25))
    ordering.add(Candy("Gummy Bears", .25, 0.35))
    ordering.add(Cookie("Chocolate Chip", 6, 3.99))
    ordering.add(IceCream("Pistachio", 2, .79))
    ordering.add(Sundae("Vanilla", 3, .69, "Hot Fudge", 1.29))
    ordering.add(Cookie("Oatmeal Raisin", 2, 3.45))
    for item in ordering.order:
        print(item.name)
    print(len(ordering))
    list = [["Candy"],["Cookie"],["IceCream"],["Sundae"]]
    list[0].append(ordering[0])
    list[0].append(ordering[0])
    list[0].append(ordering[0])
    list[0].append(ordering[0])
    list[0].append(ordering[0])
    list[0].append(ordering[0])

main()
    