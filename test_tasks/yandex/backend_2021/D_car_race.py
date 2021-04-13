# В городе Тарантасске проходят гонки без ограничений. Это значит, что одновременно
# соревноваться могут гонщики на автомобилях, мотоциклах и даже гужевых повозках.
# Скорости автомобиля и мотоцикла зависят от того, каким бензином они заправлены - 98
# позволяет ехать с полной скоростью, 95 уменьшает скорость на 10% для машин и на 20%
# для мотоциклов, 92-й - на 20% и 40% соответственно. Гужевые повозки едут с постояной скоростью.
#
# Длина кольцевой трассы равна M. Определить, какое транспортное средство будет ближе к
# финишу спустя время t после начала гонок (возможно, проходя при этом не первый круг).
# Если несколько средств будут одинаково близки, вывести нужно то, у которого меньше номер.
# Для описания транспортных средств используйте наследование классов.


from abc import ABC, abstractmethod


class Vehicle(ABC):
    def __init__(self, id: int, speed: int):
        self.id = id
        self.speed = speed
        self.remains = None

        self.calculate()

    @abstractmethod
    def calculate(self):
        """Calculate time to go for each transport."""

    def __gt__(self, other: 'Vehicle'):
        if self.remains == other.remains:
            if self.id <= other.id:
                return True
            else:
                return False

        if self.remains == 0:
            return True
        if other.remains == 0:
            return False

        if self.remains > other.remains:
            return True
        else:
            return False

    def __repr__(self):
        return '{}'.format(self.id)


class HorseCar(Vehicle):
    def __init__(self, id: int, speed: int):
        super().__init__(id, speed)

    def calculate(self):
        self.remains = (self.speed * TIME) % M


class PetrolCar(Vehicle):
    """Abstract class for car with petrol oil."""

    def __init__(self, id: int, speed: int, oil: int, percentage: dict):
        self.oil = oil
        self.percentage = percentage
        super().__init__(id, speed)

    def calculate(self):
        self.remains = (self.speed * TIME * self.percentage[self.oil]) % M


class Car(PetrolCar):
    def __init__(self, id: int, speed: int, oil: int):
        percentage = {
            98: 1,
            95: 0.9,
            92: 0.8
        }

        super().__init__(id, speed, oil, percentage)


class MotoCar(PetrolCar):
    def __init__(self, id: int, speed: int, oil: int):
        percentage = {
            98: 1,
            95: 0.8,
            92: 0.6
        }

        super().__init__(id, speed, oil, percentage)


if __name__ == '__main__':
    file_name = 'D_input.txt'

    with open(file_name) as f:
        N, M, TIME = list(map(int, f.readline().strip().split()))
        vehicles = []

        for _ in range(N):
            inputs = list(map(int, f.readline().strip().split()))

            if len(inputs) == 4:
                i, type_of_veh, speed, oil = inputs
            else:
                i, type_of_veh, speed = inputs

            if type_of_veh == 1:
                vehicles.append(Car(i, speed, oil))
            elif type_of_veh == 2:
                vehicles.append(MotoCar(i, speed, oil))
            elif type_of_veh == 3:
                vehicles.append(HorseCar(i, speed))

    for car in sorted(vehicles):
        print(f"{car.id}, {car.__class__.__name__}: {car.remains}")

    print(sorted(vehicles)[-1])

