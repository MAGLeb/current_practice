from sys import stdin, stdout

s = stdin.readline().strip()


def z_function(s: str) -> list:
    l, r = 0, 0
    z = [0 for _ in range(len(s))]

    for i in range(1, len(s)):
        if r >= i:
            z[i] = min(z[i - l], r - i + 1)
        while z[i] + i < len(s) and s[z[i]] == s[z[i] + i]:
            z[i] += 1
        if r < z[i] + i - 1:
            l = i
            r = z[i] + i - 1
    return z


stdout.write(' '.join(map(str, z_function(s))))
