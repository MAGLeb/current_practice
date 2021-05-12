from functools import cmp_to_key


def letter_cmp(a, b):
    if len(a) < len(b):
        return -1
    if len(a) > len(b):
        return 1

    return -1 if a > b else 1


letter_cmp_key = cmp_to_key(letter_cmp)

with open('input.txt') as f:
    n = int(f.readline().strip())

    lines = [line.rstrip('\n') for line in f]
    lines.sort(key=letter_cmp_key)

    for line in lines:
        print(line)
