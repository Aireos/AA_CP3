# AKA Dessert Shop Part 1

from abc import ABC, abstractmethod

class DessertItem(ABC):
    def __init__(self,name = "",tax_percent=7.25):
        self.name = name
        self.tax_percent = tax_percent

    @abstractmethod
    def calculate_cost(self):
        return
    
    def calculate_tax(self): 
        return(float(round((((self.tax_percent/100))*self.calculate_cost()))))

class Candy(DessertItem):
    def __init__(self,name = "",price_per_pound=0.0,candy_weight=0.0,tax_percent=7.5):
        super().__init__(name,tax_percent)
        self.price_per_pound = price_per_pound
        self.candy_weight = candy_weight

    def calculate_cost(self):
        return(float(self.price_per_pound*self.candy_weight))

class IceCream(DessertItem):
    def __init__(self,name = "",price_per_scoop=0.0,scoop_count=0):
        super().__init__(name)
        self.price_per_scoop = price_per_scoop
        self.scoops = scoop_count

    def calculate_cost(self):
        return(float(self.price_per_scoop*self.scoops))

class Cookie(DessertItem):
    def __init__(self,name = "",price_per_dozen=0.0,amount=0):
        super().__init__(name)
        self.price_per_dozen = price_per_dozen
        self.amount = amount

    def calculate_cost(self):
        return(float(round(self.price_per_dozen*(self.amount/12))))

class Sundae(IceCream):
    def __init__(self,name = "",price_per_scoop=0.0,scoops=0,topping_name="",topping_price=0.0):
        super().__init__(name, price_per_scoop, scoops)
        self.topping_name = topping_name
        self.topping_price = topping_price
    
    def calculate_cost(self):
        return(float((self.price_per_scoop*self.scoops)+(self.topping_price)))

class Order():
    def __init__(self):
        self.order = []
    def add(self,dessert_item):
        self.order.append(dessert_item)
    def __len__(self):
        return(len(self.order))
    def order_cost(self):
        total_cost = 0
        for i in self.order:
            total_cost += i.calculate_cost()
        return total_cost
    def order_tax(self):
        total_tax = 0
        for i in self.order:
            total_tax += i.calculate_tax()
        return total_tax