
# Итак, у вас есть корзина с грушами и несколько детей. Нужно поделить груши так,
# чтобы никому из детей не было обидно, то есть поровну. (Теперь понятно, почему в задаче дети?)
#
# Напишите класс PearsBasket, экземпляр которого при инициализации получает целое число – количество груш в корзине.
#
# В классе должны быть методы:
#
#     pb // n – деление нацело, возвращает список объектов класса со значениями количества груш
#     в каждой корзинке, если есть остаток – он должен находиться в дополнительной последней корзинке.
#
#     pb % n – получение остатка от деления, возвращает число: остаток от деления.
#     pb_1 + pb_2 – складываются две корзинки, получается новая корзина;
#     pb_1 - n – число вычитается из корзинки, если там есть такое количество груш; если нет – вычитается сколько есть, остается 0;
#      __str__ – возвращает количество груш в корзине;
#      __repr__ – возвращает строку в формате PearsBasket(<количество>).

class PearsBasket:
    def __init__(self, pears: int):
        if pears < 0:
            pears = 0
        self.pears = pears

    def __floordiv__(self, other: int):
        if self.pears == 0:
            return []

        number_new_instance = int(self.pears / other)
        remains = self.pears % other

        result = [PearsBasket(other) for _ in range(number_new_instance)]

        if remains > 0:
            result.append(PearsBasket(remains))

        return result

    def __add__(self, other):
        if isinstance(other, PearsBasket):
            return PearsBasket(self.pears + other.pears)
        self.pears += other

    def __sub__(self, other: int):
        self.pears -= other

        if self.pears <= 0:
            self.pears = 0

    def __mod__(self, number: int):
        self.pears = self.pears % number
        return self.pears

    def __str__(self):
        return f'{self.pears}'

    def __repr__(self):
        return f'{self.__class__.__name__}({self.pears})'


pb = PearsBasket(17)
pb_2 = PearsBasket(13)
pb_3 = pb + pb_2

print(pb_3)
print([pb_3])
pb_3 - 20
print(pb_3)
pb_3 + 20
print(pb_3)

pb = PearsBasket(-2)
print(pb)
pb + 100
print(pb // 99)
pb + 100
print(pb // 99)
pb + 100
print(pb // 99)
