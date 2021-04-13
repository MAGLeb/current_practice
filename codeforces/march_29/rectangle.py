from collections import Counter


def solution(l: Counter, W: int):
    result = 0

    d = dict(l)
    min_e = min(d.keys())

    while d:
        curr = W
        keys = sorted(d, reverse=True)

        for key in keys:
            if min_e > curr:
                break

            while curr >= key and d[key] > 0:
                curr -= key
                d[key] -= 1

            if d[key] == 0:
                del d[key]

        if curr != W:
            result += 1

    return result


m = int(input())

for _ in range(m):
    k, W = list(map(int, input().strip().split()))
    cnt = Counter(map(int, input().strip().split()))
    print(solution(cnt, W))



