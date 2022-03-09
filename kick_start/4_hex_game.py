from sys import stdin, stdout
from typing import List
from collections import Counter
from copy import deepcopy

BLUE_DIRECTIONS_SOUTH = ((0, 1), (-1, 1), (-1, 0), (0, -1), (1, -1), (1, 0))
BLUE_DIRECTIONS_NORTH = ((0, 1), (1, 0), (1, -1), (0, -1), (-1, 0), (-1, 1))
RED_DIRECTIONS_WEST = ((-1, 0), (0, -1), (1, -1), (1, 0), (0, 1), (-1, 1))
RED_DIRECTIONS_EAST = ((1, 0), (1, -1), (0, -1), (-1, 0), (-1, 1), (0, 1))


def solve(original_board: List[List]) -> str:
    blue, red = count_hexes(original_board)
    if abs(blue - red) > 1:
        return 'Impossible'

    board = padding(original_board)

    south_path = blue_south_path(board)
    if south_path:
        north_path = blue_north_path(board)
        if north_path and intersection(south_path, north_path) and blue >= red:
            return 'Blue wins'
        return 'Impossible'

    west_path = red_west_path(board)
    if west_path:
        east_path = red_east_path(board)
        if east_path and intersection(west_path, east_path) and red >= blue:
            return 'Red wins'
        return 'Impossible'

    return 'Nobody wins'


def get_next_hex(left, right, directions) -> tuple:
    right_dir = (right[0] - left[0], right[1] - left[1])
    for index, direction in enumerate(directions):
        if right_dir == direction:
            next_dir = directions[(index + 1) % len(directions)]
            return tuple([left[0] + next_dir[0], left[1] + next_dir[1]])


def step(board, color, left, right, directions):
    next_hex = get_next_hex(left, right, directions)

    if board[next_hex[0]][next_hex[1]] == color:
        return next_hex, right
    return left, next_hex


def red_east_path(board):
    n = len(board)
    left, right = (0, n - 2), (0, n - 1)
    path = set()

    while left[0] != n - 1:
        path.add(left)
        left, right = step(board, 'R', left, right, RED_DIRECTIONS_EAST)
        if right[1] == 0:
            return None
    return path


def red_west_path(board):
    n = len(board)
    left, right = (n - 1, n - 2), (n - 1, n - 1)
    path = set()

    while left[0] != 0:
        path.add(left)
        left, right = step(board, 'R', left, right, RED_DIRECTIONS_WEST)
        if right[1] == 0:
            return None
    return path


def blue_north_path(board):
    n = len(board)
    left, right = (0, 0), (0, 1)
    path = set()

    while left[1] != n - 1:
        path.add(left)
        left, right = step(board, 'B', left, right, BLUE_DIRECTIONS_NORTH)
        if right[0] == n - 1:
            return None
    return path


def blue_south_path(board):
    n = len(board)
    left, right = (n - 1, 0), (n - 1, 1)
    path = set()

    while left[1] != n - 1:
        path.add(left)
        left, right = step(board, 'B', left, right, BLUE_DIRECTIONS_SOUTH)
        if right[0] == 0:
            return None
    return path


def intersection(south_path: List, north_path: List):
    return len(set(south_path) - set(north_path)) < len(south_path)


def padding(original_board):
    n = len(original_board)
    board = deepcopy(original_board)

    for i in range(n):
        board[i].insert(0, 'B')
        board[i].append('B')
    board.insert(0, ['B'] + ['R' for _ in range(n)] + ['B'])
    board.append(['B'] + ['R' for _ in range(n)] + ['B'])
    return board


def count_hexes(board):
    n = len(board)
    b, r = 0, 0
    for i in range(n):
        for j in range(n):
            if board[i][j] == 'B':
                b += 1
            elif board[i][j] == 'R':
                r += 1
    return b, r


def main():
    n = int(stdin.readline().strip())

    for i in range(n):
        m = int(stdin.readline())
        board = []
        for _ in range(m):
            board.append(list(stdin.readline().strip()))

        status = solve(board)

        stdout.write("Case #" + str(i + 1) + ": " + status + '\n')


if __name__ == '__main__':
    main()
