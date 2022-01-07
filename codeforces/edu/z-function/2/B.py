from sys import stdin, stdout


n = int(stdin.readline())

for _ in range(n):
    k, j = map(int, stdin.readline().strip().split())

    if j % 2 == 1 or j == 0:
        stdout.write(str(0) + '\n')
    else:
        for i in range(0, k):
            if (j - 2**i) % 2**(i+1) == 0:
                stdout.write(str(2**i-1) + '\n')
                break


    # grey = grey_string(k)
    # z = [0, 1]
    #
    # for i in range(2, k):
    #     z = z + [0] + [2**i - 1] + z
    #
    # stdout.write(''.join(map(str, z)) + '\n')
    # if j == 0:
    #     stdout.write('0\n')
    # else:
    #     stdout.write(str(z[j-1]) + '\n')


# def list_alphabet():
#     return list(string.ascii_lowercase)
#
#
# def grey_string(q: int) -> str:
#     res = 'a'
#     alphabet = list_alphabet()
#
#     for i in range(1, q):
#         res = res + alphabet[i] + res
#
#     return res

#1 2 6 10 14 18 22 26 30
#3 4 12 20 28 36
#7 8 24 40
#15 16 48

# a
# 0
# aba
# 001
# abacaba
# 0010301
# abacabadabacaba
# 001030107010301
# abacabadabacabaeabacabadabacaba
# 00103010701030101010301070103010


# 0010301070 1 0 3 0 1 0 15 0 1 0 3 0 1 0 7 0 1 0 3 0 1
# 0123456789 101112131415161718192021222324252627282930