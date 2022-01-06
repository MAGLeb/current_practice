n = int(input())


def is_palindrom(s):
    i, j = 0, len(s) - 1

    while i <= j:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1

    return True


for _ in range(n):
    s = str(input().strip())
    mx = 0

    for i in range(len(s), 0, -1):
        if is_palindrom(s[0:i]):
            mx = i
            break

    print(mx)
