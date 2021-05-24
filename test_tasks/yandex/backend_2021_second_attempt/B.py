dictionary = {
    0: 'A',
    1: 'B',
    2: 'C',
    3: 'SPACE',
    4: 'D',
    5: 'E',
    6: 'F'
}


def find_place(n, s, l, a):
    plcs = []

    if s == 'left':
        if l == 'aisle':
            for index, row in enumerate(a):
                if '#' not in row[3 - n : 3]:
                    for j in range(3 - n, 3):
                        plcs.append((index, j))
                    return plcs
            return plcs
        else:
            for index, row in enumerate(a):
                if '#' not in row[0 : n]:
                    for j in range(0, n):
                        plcs.append((index, j))
                    return plcs
            return plcs
    else:
        if l == 'window':
            for index, row in enumerate(a):
                if '#' not in row[7 - n: 7]:
                    for j in range(7 - n, 7):
                        plcs.append((index, j))
                    return plcs
            return plcs
        else:
            for index, row in enumerate(a):
                if '#' not in row[4 : 4 + n]:
                    for j in range(4, 4 + n):
                        plcs.append((index, j))
                    return plcs
            return plcs


with open('input.txt') as f:
    n = int(f.readline().strip())
    seats = []

    for i in range(n):
        seats.append(list(f.readline().strip()))

    m = int(f.readline().strip())

    for i in range(m):
        number, side, loc = map(lambda x: int(x) if x.isnumeric() else x, f.readline().strip().split())

        places = find_place(number, side, loc, seats)

        if len(places) == 0:
            print("Cannot fulfill passengers requirements")
        else:
            print("Passengers can take seats:", end="")
            index_row = places[0][0]
            index_places = list(map(lambda x: x[1], places))

            for i in index_places:
                print(f" {index_row + 1}{dictionary[i]}", end="")
            print()

            for i, row in enumerate(seats):
                for j, item in enumerate(row):
                    if i == index_row and j in index_places:
                        print('X', end='')
                        seats[i][j] = '#'
                    else:
                        print(item, end='')
                print()
