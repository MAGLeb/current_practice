def search(arr, l, h, key):
    if l > h:
        return -1

    mid = (l + h) // 2
    if arr[mid][2] == key:
        return mid

    if arr[l][2] <= arr[mid][2]:
        if arr[l][2] <= key <= arr[mid][2]:
            return search(arr, l, mid - 1, key)
        return search(arr, mid + 1, h, key)

    if arr[mid][2] <= key <= arr[h][2]:
        return search(arr, mid + 1, h, key)
    return search(arr, l, mid - 1, key)


n = int(input().strip())
dictionary = {}
array = []

for i in range(n):
    pair = tuple(map(int, input().strip().split()))
    pair += (i, )
    array.append(pair)

    if pair[0] == pair[1]:
        if pair[0] not in dictionary:
            dictionary[pair[0]] = [pair]
        else:
            dictionary[pair[0]] += [pair]
        continue

    for x in pair[:2]:
        if x not in dictionary:
            dictionary[x] = [pair]
        else:
            dictionary[x] += [pair]

result = 0

print(dictionary)
print(array)

for element in array:
    x, y, index = element

    if x == y:
        result += len(dictionary[x][search(dictionary[x], 0, len(dictionary[x]), index) + 1:])
    else:
        x_array = set(dictionary[x][search(dictionary[x], 0, len(dictionary[x]), index) + 1:])
        y_array = set(dictionary[y][search(dictionary[y], 0, len(dictionary[y]), index) + 1:])

        if len(x_array) > len(y_array):
            for el in y_array:
                x_array.add(el)

            result += len(x_array)
        else:
            for el in x_array:
                y_array.add(el)

            result += len(y_array)

print(result)


