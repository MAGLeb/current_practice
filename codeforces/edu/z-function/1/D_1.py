from sys import stdin, stdout

n = int(stdin.readline())

for _ in range(n):
    s = stdin.readline().strip()
    t = stdin.readline().strip()

    index = []
    for i in range(len(s) - len(t) + 1):
        if s[i:i + len(t)] == t:
            index.append(i + len(t) - 1)

    res = 0
    inter = 0
    j = 0
    i = 0
    while i < len(s):
        if j == len(index) or i != index[j]:
            inter += 1
            res += inter
        else:
            inter = 0
            i = index[j] - len(t) + 1
            j += 1
            res -= sum(i for i in range(len(t) - 1))
        i += 1

    stdout.write(str(res) + '\n')


# 'abcdefgh'
# 'a,
# ab, b,
# abc, bc, c,
# abcd, bcd, cd, d,
# abcde, bcde, cde, de, e,
# abcdef, bcdef, cdef, def, ef, f,
# abcdefg, bcdefg, cdefg, defg, efg, fg, g,
# 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28

# 'e,
# ef, f,
# efg, fg, g
# efgh, fgh, gh, h'

# g,
# gh, h

# f,
# fg, g,
# fgh, gh, h'