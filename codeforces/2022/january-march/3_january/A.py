from sys import stdin, stdout


t = int(input())

for _ in range(t):
    n, k = map(int, stdin.readline().rstrip().split())

    if k * 2 - 1 > n:
        print('-1')
    else:
        for i in range(n):
            for j in range(n):
                if i == j and i % 2 == 0 and k > 0:
                    print('R', end='')
                    k -= 1
                else:
                    print('.', end='')
            print()
