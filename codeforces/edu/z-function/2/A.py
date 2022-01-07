from sys import stdin, stdout

s = stdin.readline().strip()

res = [0]

for i in range(1, len(s)):
    inter = 0
    for l_1, l_2 in zip(s, s[i:]):
        if l_1 == l_2:
            inter += 1
        else:
            break
    res.append(inter)

stdout.write(' '.join(map(str, res)))

