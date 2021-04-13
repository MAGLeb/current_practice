f = open('input.txt', 'r')
s = f.readline().strip()


def solution(string):
    hashmap = set()
    result = []

    start, end = (0, 1)

    while start < len(string):
        substring = string[start: end]

        if substring and substring not in hashmap:
            hashmap.add(substring)
            result.append(substring)
            start = end

        end += 1
