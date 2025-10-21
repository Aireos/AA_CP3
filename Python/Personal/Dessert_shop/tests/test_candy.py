#AKA Dessert Shop Part 1

from dessert import Candy, DessertItem

def test_Candy_set():
    test_candy = Candy("None",0.0,0.0)
    assert test_candy.name == "None"
    assert test_candy.price_per_pound == 0.0
    assert test_candy.candy_weight == 0.0
