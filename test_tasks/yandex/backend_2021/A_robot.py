

# Напишите класс Robot, который инициализируется с начальными координатами –
# положением Робота на плоскости, обе координаты заключены в пределах от 0 до 100.
#
# Робот может передвигаться на одну клетку вверх (N), вниз (S), вправо (E), влево (W).
# Выйти за границы плоскости Робот не может.
#
# Метод move() принимает строку – последовательность команд перемещения робота,
# каждая буква строки соответствует перемещению на единичный интервал в направлении,
# указанном буквой. Метод возвращает кортеж координат – конечное положение Робота после перемещения.
#
# Метод path() вызывается без аргументов и возвращает список кортежей координат
# точек, по которым перемещался Робот при последнем вызове метода move. Если метод
# не вызывался, возвращает список с одним кортежем – начальным положением Робота.

MAX_Y = 100
MAX_X = 100
MIN_Y = 0
MIN_X = 0


class Robot:
    def __init__(self, coords: tuple):
        x = coords[0]
        y = coords[1]

        if MAX_X < x < MIN_X or MAX_Y < y < MIN_Y:
            message = f'The robot coordinates are incorrect. X coordinate' \
                      f' should be less than: {MAX_X} and y: {MAX_Y} and more than x: {MIN_X}' \
                      f' and y: {MIN_Y}. Yours coordinates: {x}, {y}'
            raise IndexError(message)

        self.x = x
        self.y = y
        self.history = [(x, y)]

    def move(self, commands: str):
        self.history = [(self.x, self.y)]

        for command in commands:
            self._check_borders(command)

            if command == 'N':
                self.y += 1
            elif command == 'S':
                self.y -= 1
            elif command == 'W':
                self.x -= 1
            elif command == 'E':
                self.x += 1

            self.history.append((self.x, self.y))

        return self.history[-1]

    def _check_borders(self, command: chr):
        if self.x == MAX_X and command == 'N' or self.y == MAX_Y and command == 'E' or\
           self.x == MIN_X and command == 'S' or self.y == MIN_Y and command == 'W':
            raise IndexError('You are going beyond the borders.')

    def path(self):
        return self.history


r = Robot((0, 0))
print(r.move('NENW'))
print(*r.path())
