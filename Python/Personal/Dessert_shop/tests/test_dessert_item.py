#AKA Dessert Shop Part 1

from dessert import DessertItem

def test_DessertItem_set():
    test_dessert_item = DessertItem("None")
    assert test_dessert_item.name == "None"
