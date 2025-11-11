#AKA Notes?

from dataclasses import dataclass, field
from collections import namedtuple

Color = namedtuple('Color', ['red', 'green', 'blue'])
red = Color(255, 0, 0)
print(red)

@dataclass(order=True, frozen=True)

class Person:
    sort_index: int = field(init=False, repr=False)
    name: str
    job: str
    age: int

    def __post_init__(self):
        object.__setattr__(self, 'sort_index', self.age)

person1 = Person("Tia", "Sales", 29)
person2 = Person("Tia", "Dispatch", 35)
person3 = Person("Tia", "Dispatch", 35)

print(person1)
print(person2 == person3)
print(person1 > person2)

people = [person1, person2, person3]

nums = [5, 3, 9, 1, 7, 6, 2, 8, 4]
sort_nums = sorted(nums, reverse=True)
print(sort_nums)

# def age_sort(person):
#     return person.age

# age_sorted_people = sorted(people, key=lambda person: person.age)
# print(age_sorted_people)

from operator import attrgetter
sort_people = sorted(people, key=attrgetter('job'))
print(sort_people)