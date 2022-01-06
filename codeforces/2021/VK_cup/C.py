import math


def solution(n):
    if n == 2:
        print(-1)
        return

    def max_side(m):
        return math.ceil(m ** (1/2)) - 1

    mx = max_side(n)
    remains = n - mx ** 2

    if remains % 2 == 0:
        print(mx + 1)
        remains = int(remains / 2)

        print(''.join(['o' for _ in range(remains)] + ['.' for _ in range(mx + 1 - remains)]))

        for j in range(mx):
            if mx - j <= remains:
                print(''.join(['o' for _ in range(mx + 1)]))
            else:
                print(''.join(['o' for _ in range(mx)] + ['.']))
    else:
        a = []
        tmp = n

        while tmp != 0:
            if tmp == 2:
                a[0] += 1
                break
            else:
                while mx * 2 + 1 > tmp:
                    mx -= 1
                tmp -= mx * 2 + 1
                a.append(mx)
                mx -= 1

        mx = a[0]
        ln = mx + 1
        res = [['.' for _ in range(ln)] for _ in range(ln)]

        for j in range(ln):
            for i in range(ln):
                if i + j > mx:
                    res[j][i] = res[mx - i][mx - j]
                    continue

                if i >= len(a):
                    break

                v = a[i]
                diff = mx - (v + i + j)
                if diff <= 0:
                    res[j][i] = 'o'
                else:
                    break

        print(len(res))
        for row in res:
            print(''.join(row))


l = int(input().strip())
solution(l)

# for l in range(1, 100):
#     print(l)
#     solution(l)



    # for j in range(mx):
    #     row = []
    #
    #     if j >= len(a):
    #         row += ['o' for _ in range(mx)]
    #         break
    #
    #     for i, v in enumerate(a):
    #         diff = mx - 1 - v - i - j
    #         if diff <= 0:
    #             row.append('o')
    #             if i


    #
    #
    # for j in range(mx + 1):
    #     row = []
    #     for i, v in enumerate(a):
    #         if mx - v >= i + j:
    #             row.append('o')
    #         else:
    #             row += ['.' for _ in range(mx - (i + 1))]
    #             break
    #
    #     print(''.join(row))

    # [6, 4, 3, 2, 1]
    # o******
    # ooooo**
    # oooooo*
    # oooooo*
    # oooooo*
    # oooooo*
    # ooooooo
    #
    # 37 - 13 - 9 - 7 - 5 - 3 = 0
