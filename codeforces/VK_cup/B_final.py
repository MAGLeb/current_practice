n = int(input().strip())
d = {}
a = []

for i in range(n):
    pair = tuple(map(int, input().strip().split()))
    pair += (i, )
    a.append(pair)

ans = 0
for el in a[::-1]:
    for j, key in enumerate([el[0], el[1]]):
        if j == 1 and el[0] == el[1]:
            continue
        if key in d:
            ans += d[key]
            d[key] += 1
        else:
            d[key] = 1
        if j == 1:
            key = tuple(sorted(el[:2]))
            if key in d:
                ans -= d[key]
                d[key] += 1
            else:
                d[key] = 1

print(ans)
