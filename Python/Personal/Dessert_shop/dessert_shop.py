# AKA Dessert Shop Part 2

from dessert import *
from tabulate import tabulate

class DessertShop:
    def user_prompt_candy(self):
        while True:
            name = input("Enter name of candy: ")
            weight = self.get_positive_float("Enter weight: ")
            price_per_pound = self.get_positive_float("Enter price per pound: ")
            return Candy(name, weight, price_per_pound)

    def user_prompt_cookie(self):
        while True:
            name = input("Enter name of cookie: ")
            quantity = self.get_positive_int("Enter quantity: ")
            price_per_dozen = self.get_positive_float("Enter price per dozen: ")
            return Cookie(name, quantity, price_per_dozen)

    def user_prompt_icecream(self):
        while True:
            flavor = input("Enter the type of ice cream: ")
            scoops = self.get_positive_int("Enter the number of scoops: ")
            price_per_scoop = self.get_positive_float("Enter the price per scoop: ")
            return IceCream(flavor, scoops, price_per_scoop)

    def user_prompt_sundae(self):
        while True:
            flavor = input("Enter the type of ice cream: ")
            scoops = self.get_positive_int("Enter the number of scoops: ")
            topping = input("Enter topping: ")
            topping_price = self.get_positive_float("Enter the price for the topping: ")
            return Sundae(flavor, scoops, topping, topping_price)

    def get_positive_float(self, prompt):
        while True:
            try:
                value = float(input(prompt))
                if value < 0:
                    raise ValueError("Value must be positive.")
                return value
            except ValueError as e:
                print(e)

    def get_positive_int(self, prompt):
        while True:
            try:
                value = int(input(prompt))
                if value < 0:
                    raise ValueError("Value must be positive.")
                return value
            except ValueError as e:
                print(e)

def main():
    ordering = Order()
    shop = DessertShop()

    while True:
        print("1: Candy\n2: Cookie\n3: Ice Cream\n4: Sundae")
        choice = input("What would you like to add to the order? (1-4, Enter for done): ")

        if choice == "":
            break
        elif choice == "1":
            ordering.add(shop.user_prompt_candy())
        elif choice == "2":
            ordering.add(shop.user_prompt_cookie())
        elif choice == "3":
            ordering.add(shop.user_prompt_icecream())
        elif choice == "4":
            ordering.add(shop.user_prompt_sundae())
        else:
            print("Invalid choice. Please select from 1-4 or press Enter to finish.")

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

main()