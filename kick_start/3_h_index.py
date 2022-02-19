from sys import stdin, stdout
from typing import List


def get_h_index(c: List[int]):
    result = [0]
    d = {0: 1}

    for i in range(len(c)):
        number = c[i]

        if number in d:
            d[number] += 1
        else:
            d[number] = 1

        counter = 0
        last_elem = result[-1]
        for key in sorted(d):
            if key in d and key > last_elem:
                counter += d[key]

        if counter > last_elem:
            result.append(counter)
            if last_elem in d:
                del d[last_elem]
        else:
            result.append(last_elem)

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
