from sys import stdin, stdout, maxsize
from operator import itemgetter

t = int(input())

for _ in range(t):
    n = int(input())
    mN, cN = maxsize, maxsize
    mX, cX = 0, maxsize
    mL, cL = 0, maxsize

    for _ in range(n):
        a = list(map(int, stdin.readline().rstrip().split()))

        if a[0] < mN:
            mN = a[0]
            cN = maxsize
        if a[0] == mN:
            cN = min(cN, a[2])

        if a[1] > mX:
            mX = a[1]
            cX = maxsize
        if a[1] == mX:
            cX = min(cX, a[2])

        if a[1] - a[0] + 1 > mL:
            mL = a[1] - a[0] + 1
            cL = maxsize
        if a[1] - a[0] + 1 == mL:
            cL = min(cL, a[2])

        ans = cN + cX
        if mL == mX - mN + 1:
            ans = min(ans, cL)

        stdout.write(str(ans) + '\n')
