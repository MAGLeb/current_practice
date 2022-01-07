from sys import stdin, stdout

n = int(stdin.readline())

for _ in range(n):
    s = stdin.readline().strip()
    t = stdin.readline().strip()

    res = 0
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            curr = s[i:j]
            index = 0

            flag = True
            for e in range(len(curr) - len(t) + 1):
                if curr[e:e+len(t)] == t:
                    flag = False
                    break

            if flag:
                res += 1
            else:
                break

    stdout.write(str(res) + '\n')
