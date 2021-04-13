f = open('input.txt', 'r')

result = []
a = []
n = int(f.readline())

for _ in range(n):
    flag = False
    storages = set(f.readline().strip().split(' '))

    for hashmap in a:
        for key in storages:
            if key in hashmap:
                hashmap |= storages
                flag = True

        if flag:
            break

    if not flag:
        a.append(storages)

k = int(f.readline())

for _ in range(k):
    key, number = list(f.readline().strip().split(' '))
    storages = list(f.readline().strip().split(' '))
    cur_result = []

    for storage in storages:
        for cluster in a:
            if key in cluster and storage in cluster:
                cur_result.append(storage)

    print(f"{len(cur_result)} {' '.join(cur_result)}")



