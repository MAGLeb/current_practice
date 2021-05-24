class TrafficLight:
    def __init__(self):
        self.color = 'blue'
        self.locked = False

    def change_color(self, color):
        if not self.locked:
            self.color = color

    def lock(self):
        self.locked = True

    def unlock(self):
        self.locked = False


n = int(input().strip())
traffic_light = TrafficLight()

for _ in range(n):
    command = input().strip()

    if command == 'lock':
        traffic_light.lock()
    elif command == 'unlock':
        traffic_light.unlock()
    else:
        traffic_light.change_color(command)

print(traffic_light.color)


