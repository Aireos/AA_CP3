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
    list[0].append(ordering.order[0])
    list[0].append(ordering.order[1])
    list[1].append(ordering.order[2])
    list[2].append(ordering.order[3])
    list[3].append(ordering.order[4])
    list[2].append(ordering.order[5])
    list_of_lists = []
    for i in ordering.order:
        list_of_lists.append([i.name,i.calculate_cost(),i.calculate_tax()])
    list_of_lists.append(["Subtotal",ordering.order_cost(), ordering.order_tax()])
    list_of_lists.append(["Total","",ordering.order_cost()*ordering.order_tax()])
    list_of_lists.append(["Number of items","",ordering.__len__()])
    print(tabulate.tabulate(list_of_lists, headers=["item","cost","tax"]))

main()
    