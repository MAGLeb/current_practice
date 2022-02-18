from sys import stdin, stdout
from typing import List


def get_h_index(c: List[int]):
    result = []
    d = {0: 0}
    ans = 0
    curr = 0

    for i in range(len(c)):
        number = c[i]

        if number in d:
            d[number] += 1
        else:
            d[number] = 1

        if ans in d:
            key = ans
            ans -= d[key]
            del d[key]

        ans += 1
        curr = max(ans, curr)
        result.append(curr)

    return result


def main():
    n = int(stdin.readline().strip())

    for i in range(n):
        stdin.readline()
        citations = list(map(int, stdin.readline().strip().split(' ')))
        h_index = get_h_index(citations)

        stdout.write("Case #" + str(i+1) + ": " + ' '.join(map(str, h_index)) + '\n')


if __name__ == '__main__':
    main()
