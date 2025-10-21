#AKA Dessert Shop Part 1

from dessert import Sundae, IceCream, DessertItem

def test_Sundae_set():
    test_sundae = Sundae("None",0.0,0,"None",0.0)
    assert test_sundae.name == "None"
    assert test_sundae.price_per_scoop == 0.0
    assert test_sundae.scoops == 0
    assert test_sundae.topping_name == "None"
    assert test_sundae.topping_price == 0.0
