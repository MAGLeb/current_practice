import heapq

f = open('input.txt', 'r')

n = int(f.readline())
teams = list(map(int, f.readline().strip().split(' ')))

k = int(f.readline())
heap = []

for _ in range(k):
    capacity, value = list(map(int, f.readline().strip().split(' ')))
    heapq.heappush(heap, [-capacity, value])


def solution():
    current = [0, 0]

    for team in sorted(teams, reverse=True):
        if current[1] == 0:
            if heap:
                current = list(map(abs, (heapq.heappop(heap))))
            else:
                return 'No'

        if team <= current[0]:
            current[1] -= 1
        else:
            return 'No'

    return 'Yes'


print(solution())



