def solution():
    n = int(input().strip())
    a = sorted(list(map(int, input().strip().split())))
    d = {}
    m = 0

    for i in range(n - 1):
        if a[i] == a[i + 1]:
            if a[-1] != 0:
                continue
        if a[i] > 0:
            m = a[i]
            break
        diff = abs(a[i] - a[i + 1])

        if diff in d:
            d[diff] += 1
        else:
            d[diff] = 2

    keys = list(filter(lambda x: x >= m, d.keys()))
    result = 0

    for key in keys:
        result += d[key]

    if result == 0:
        return 1
    return result - 1


k = int(input().strip())

for _ in range(k):
    print(solution())
