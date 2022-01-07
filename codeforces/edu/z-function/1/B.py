from sys import stdin, stdout

n = int(stdin.readline())

for _ in range(n):
    s = stdin.readline().strip()
    res = 0

    for i in range(len(s)):
        for j in range(i, len(s)+1):
            condition_1 = s[i:j] == s[0:j-i]
            condition_2 = s[i:j] == s[len(s)-j+i:]
            if condition_1 and not condition_2 or condition_2 and not condition_1:
                res += 1
    stdout.write(str(res) + '\n')
