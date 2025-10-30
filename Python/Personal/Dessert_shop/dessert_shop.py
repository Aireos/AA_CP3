# AKA Dessert Shop Part 2

from dessert import *
from tabulate import tabulate

def main():
    ordering = Order()
    ordering.add(Candy("Candy Corn", 1.5, 0.25))
    ordering.add(Candy("Gummy Bears", 0.25, 0.35))
    ordering.add(Cookie("Chocolate Chip", 6, 3.99))
    ordering.add(IceCream("Pistachio", 2, 0.79))
    ordering.add(Sundae("Vanilla", 3, 0.69, "Hot Fudge", 1.29))
    ordering.add(Cookie("Oatmeal Raisin", 2, 3.45))

    list_of_lists = []
    for item in ordering.order:
        list_of_lists.append([item.name, f"{item.calculate_cost():.2f}", f"{item.calculate_tax():.2f}"])

    subtotal = ordering.order_cost()
    total_tax = ordering.order_tax()
    total = subtotal + total_tax
    list_of_lists.append(["Subtotal", f"{subtotal:.2f}", f"{total_tax:.2f}"])
    list_of_lists.append(["Total", f"{total:.2f}", ""])
    list_of_lists.append(["Number of items", len(ordering), ""])

    print(tabulate(list_of_lists, headers=["Item", "Cost", "Tax"]))


if __name__ == "__main__":
    main()