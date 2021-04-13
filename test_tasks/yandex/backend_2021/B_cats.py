

# При наследовании классов класс-наследник обычно имеет больший функционал, чем родительский класс.
# А у котов все наоборот. Кошка по сравнению с котенком умеет ловить мышей (котенок пока нет) и
# мяукает громче (CAPS LOCK`ом). Поэтому логично кошку наследовать от котенка…
#
# Напишите классы:
#
# Класс АбстрактныйКот (AbstractCat), который инициализируется без аргументов. Умеет:
# – eat – есть. За каждые 10 единиц еды вес увеличивается на 1 единицу,
# пока не станет 100, дальше не растет. Если при одном приеме пищи количество
# еды не кратно 10, остаток запасается, а потом суммируется с новой едой.
#
# – возвращать строковое представление в виде <Имя класса> (вес).
#
# Класс Котенок (Kitten), наследуется от кота с аргументом вес. Умеет мяукать тоненько:
# – meow – возвращает строку "meow..."
# Еще умеет спать – sleep – возвращает строку Snore, повторенную столько раз, сколько число 5 помещается в весе.
#
# Класс Кошка (Cat), наследуется от котенка с аргументами вес и кличка. Умеет мяукать громко (meow):
# "MEOW..."
# и возвращать свое имя (get_name). Также умеет ловить мышей:
# – catch_mice – возвращает строку: Got it!


from abc import ABC


MAX_WEIGHT = 100


class AbstractCat(ABC):
    def __init__(self):
        self.weight = 0
        self.remains = 0

    def eat(self, food):
        food += self.remains
        self.weight += int(food / 10)
        self.remains = food % 10

        if self.weight > MAX_WEIGHT:
            self.weight = MAX_WEIGHT

    def __repr__(self):
        return "{name} ({weight})".format(name=self.__class__.__name__, weight=self.weight)

    def __str__(self):
        return "{name} ({weight})".format(name=self.__class__.__name__, weight=self.weight)


class Kitten(AbstractCat):
    def __init__(self, weight: int):
        super().__init__()
        self.weight = weight

    def sleep(self):
        number = int(self.weight / 5)

        return 'Snore' * number

    @staticmethod
    def meow():
        return 'meow...'


class Cat(Kitten):
    def __init__(self, weight: int, nickname: str):
        super().__init__(weight)
        self.nickname = nickname

    def get_name(self):
        return self.nickname

    @staticmethod
    def meow():
        return 'MEOW...'

    @staticmethod
    def catch_mice():
        return 'Got it!'




abscat = AbstractCat()
abscat.eat(125)
abscat.eat(17)
print(abscat)
kit = Kitten(21)
print(kit.sleep())
cat = Cat(83, 'Molly')
print(cat.meow())
print(cat.get_name())


kit = Kitten(15)
kit.eat(24)
print(kit)
cat = Cat(41, 'Molly')
print(cat.catch_mice())
print(cat)
