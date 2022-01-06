from sys import stdin, stdout


t = int(input())

for _ in range(t):
    n = int(input())
    mN = None
    mX = None

    for _ in range(n):
        a = list(map(int, stdin.readline().rstrip().split()))

        if mN is None and mX is None:
            mN = a
            mX = a
        else:
            if a[0] < mN[0] or a[0] == mN[0] and a[2] < mN[2]:
                mN = a

            if a[1] > mX[1] or a[1] == mX[1] and a[2] < mX[2]:
                mX = a

        if mN == mX or mN[0] == mX[0]:
            stdout.write(str(mX[2]) + '\n')
        else:
            stdout.write(str(mN[2] + mX[2]) + '\n')
