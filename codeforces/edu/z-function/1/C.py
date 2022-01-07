from sys import stdout, stdin

n = int(stdin.readline())

for _ in range(n):
    s = stdin.readline().strip()
    t = stdin.readline().strip()

    if len(t) > len(s):
        stdout.write('0' + '\n' + '\n')
    else:
        res = []
        for i in range(len(s) - len(t) + 1):
            curr = s[i:i+len(t)]
            flag = True
            for j in range(len(curr)):
                if t[j] == '?' or curr[j] == t[j]:
                    continue
                else:
                    flag = False
                    break
            if flag:
                res.append(str(i))

        stdout.write(str(len(res)) + '\n')
        stdout.write(str(' '.join(res)) + '\n')

