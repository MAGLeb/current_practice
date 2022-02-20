from sys import stdin, stdout
from typing import List


def get_h_index(c: List[int]):
    result = [0]
    d = {0: 0}
    counter = 0

    for i in range(len(c)):
        number = c[i]
        last_elem = result[-1]

        if number > last_elem:
            if number in d:
                d[number] += 1
            else:
                d[number] = 1
            counter += 1

        if counter > last_elem:
            if last_elem in d:
                counter -= d[last_elem]
                del d[last_elem]
        result.append(max(counter, last_elem))

    return result[1:]


def main():
    n = int(stdin.readline().strip())

    for i in range(n):
        stdin.readline()
        citations = list(map(int, stdin.readline().strip().split(' ')))
        h_index = get_h_index(citations)

        stdout.write("Case #" + str(i+1) + ": " + ' '.join(map(str, h_index)) + '\n')


if __name__ == '__main__':
    main()
