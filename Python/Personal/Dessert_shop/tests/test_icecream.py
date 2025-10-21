#AKA Dessert Shop Part 1

from dessert import IceCream, DessertItem

def test_IceCream_set():
    test_icecream = IceCream("None",0.0,0)
    assert test_icecream.name == "None"
    assert test_icecream.price_per_scoop == 0.0
    assert test_icecream.scoops == 0
