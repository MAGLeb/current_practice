from collections import Counter


def solution():
    n = int(input().strip())
    dictionary = Counter(list(map(int, input().strip().split())))

    if len(dictionary.keys()) == 1:
        return 0

    return n - dictionary[sorted(dictionary.keys())[0]]


m = int(input().strip())

for _ in range(m):
    print(solution())


