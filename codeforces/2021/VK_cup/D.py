from typing import Optional


class TrafficLight:
    def __init__(self):
        self.history = [(False, 'blue', None)]
        self.color = 'blue'
        self.locked = False

    def execute(self, command: Optional[str], cache: bool = True, index: int = None):
        if command == 'lock':
            flag = True
            self.toggle(flag)
        elif command == 'unlock':
            flag = False
            self.toggle(flag)
        else:
            flag = command
            self.change_color(flag)

        if cache:
            self.history.append((self.locked, self.color, flag))
        elif index < len(self.history):
            self.history[index] = (self.locked, self.color, flag)

    def change_color(self, color):
        if not self.locked:
            self.color = color

    def toggle(self, locked):
        self.locked = locked

    def change_history(self, command, index):
        prev_locked = self.history[index - 1][0]
        prev_color = self.history[index - 1][1]

        if command == 'lock' or command == 'unlock':
            if command == 'lock':
                command = True
            else:
                command = False
            self.history[index] = (command, prev_color, command)
        elif prev_locked:
            self.history[index] = (prev_locked, prev_color, command)
        else:
            self.history[index] = (prev_locked, command, command)

        self._resume(index)

        print(self.color)

    def _resume(self, index):
        self._curr_state(index)

        for i, el in enumerate(self.history[index + 1:]):
            if isinstance(el[2], str):
                command = el[2]
            elif el[2]:
                command = 'lock'
            else:
                command = 'unlock'

            self.execute(command, False, i + index + 1)

    def _curr_state(self, index):
        self.locked = self.history[index][0]
        self.color = self.history[index][1]


n = int(input().strip())
traffic_light = TrafficLight()

for _ in range(n):
    command = input().strip()
    traffic_light.execute(command)

print(traffic_light.color)

n = int(input().strip())

for _ in range(n):
    _ = input().strip().split()
    j = int(_[0])
    command = _[1]
    traffic_light.change_history(command, j)




