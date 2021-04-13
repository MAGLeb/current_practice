import numpy as np

filename = 'b_little_bit_of_everything.txt'
array = []

with open(filename, 'r') as f:
    m, t_2, t_3, t_4 = list(map(int, f.readline().strip().split()))
    matrix = [[] for _ in range(m)]

    for i in range(m):
        array.append(f.readline().strip().split()[1:])

        for j in range(i):
            if i == j:
                matrix[i][j] = 0
            if i > j:
                continue

            matrix[i][j] = len(set(array[i] + array[j]))


def best_four():
    inds, max_el = max_elem(matrix)

    



def max_elem(in_mat):
    l_m = np.array(in_mat)
    result = np.where(l_m == np.amax(l_m))
    indexes = list(zip(result[0], result[1]))

    return np.amax(l_m), indexes

