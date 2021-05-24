with open('input.txt') as f:
    n = int(f.readline().strip())
    a = list(map(int, f.readline().strip().split()))


def solution():
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            return -1
    return a[n - 1] - a[0]


print(solution())
