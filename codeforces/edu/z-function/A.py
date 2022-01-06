from sys import stdin, stdout

n = int(stdin.readline())


def is_palindrome(s: str) -> bool:
    start, end = 0, len(s) - 1

    while start <= end:
        if s[start] != s[end]:
            return False
        start += 1
        end -= 1
    return True


for _ in range(n):
    s = stdin.readline()
    res = 0

    for i in range(len(s), 0, -1):
        if is_palindrome(s[0:i]):
            res = i
            break

    stdout.write(str(res) + '\n')
