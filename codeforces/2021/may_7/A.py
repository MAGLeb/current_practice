from enum import Enum


class TypeNumber(Enum):
    good = 'Good'
    nearly_good = 'Nearly good'
    bad = 'Bad'


def is_good(x: int, a: int, b: int):
    if x % (a * b) == 0:
        return TypeNumber.good
    elif x % a == 0:
        return TypeNumber.nearly_good
    return TypeNumber.bad


def x_are_positive(x_1, x_2, x_3):
    return x_1 >= 0 and x_2 >= 0 and x_3 >= 0


def x_are_different(x_1, x_2, x_3):
    return x_1 != x_2 and x_2 != x_3 and x_1 != x_3



n = int(input())

for _ in range(n):
    a, b = list(map(int, input().strip().split()))
    first = a
    second = a * b
    third = a * (b + 1)

    if b == 1:
        print('NO')
        continue

    print("YES")
    print(f"{first} {second} {third}")
