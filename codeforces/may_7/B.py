import sys
n = int(input())

for _ in range(n):
    m = int(input())
    a = list(map(int, input().strip().split()))
    pos = 0
    x = sys.maxsize

    for i, num in enumerate(a):
        if num < x:
            x = num
            pos = i

    print(m - 1)
    for i, num in enumerate(a):
        if i == pos:
            continue

        print(i + 1, pos + 1, x + abs(i - pos), x)
