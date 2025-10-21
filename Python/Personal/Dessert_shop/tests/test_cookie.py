#AKA Dessert Shop Part 1

from dessert import Cookie, DessertItem

def test_Cookie_set():
    test_cookie = Cookie("None",0.0,0)
    assert test_cookie.name == "None"
    assert test_cookie.price_per_dozen == 0.0
    assert test_cookie.amount == 0
