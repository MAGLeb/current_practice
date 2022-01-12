from sys import stdin, stdout

n = int(stdin.readline())

for _ in range(n):
    k = int(stdin.readline())
    a = list(map(int, stdin.readline().strip().split()))
    stdout.write(str(max(a) - min(a)) + '\n')
