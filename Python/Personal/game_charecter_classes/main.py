# AKA Game Character Classes

class Character():
    def __init__(self, health, damage):
        self.health = health
        self.damage = damage
    def __str__(self):
        pass
class Warrior(Character):
    def __init__(self, health, damage, name):
        super().__init__(health,damage)
        self.name = name
    def __str__(self):
        return(f"{self.name} has {self.health} health and does {self.damage} damage.")
    