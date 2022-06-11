from sys import stdin, stdout

n = int(stdin.readline())

for _ in range(n):
    a, b, c = map(int, stdin.readline().strip().split())

    if b + c == a and b == c or a + b == c and a == b or abs(2 * b - a - c) == b:
        stdout.write('NO\n')
    elif (2 * b - a) % c == 0\
    or (2 * b - c) % a == 0\
    or (2 * b - a - c) % b == 0:
        stdout.write('YES\n')
    else:
        stdout.write('NO\n')
