def rec(n, k, d=True):

    if n == 1:
        return 1

    if not d and K - k == 0:
        return 1

    if k == 0:
        return 1

    return rec(n - 1, K - k, not d) + rec(n, k - 1, d)


# k - fields, n - molecula
for k, n in [[2,3], [2,2], [3,1], [1,3], [1,1], [1,500], [5,5], [3, 4], [9,9]]:
    K = k
    print(rec(n, k))
