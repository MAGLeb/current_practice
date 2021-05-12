import sys

with open('input.txt') as f:
    n = int(f.readline().strip())
    array = list(map(int, f.readline().strip().split()))

    result = sys.maxsize
    left_min = array[0]

    print(0)
    print(0)

    for i in range(1, n - 1):
        if result > left_min + array[i + 1]:
            result = left_min + array[i + 1]

        if left_min > array[i]:
            left_min = array[i]

        if result == sys.maxsize:
            print(0)
        else:
            print(result)
