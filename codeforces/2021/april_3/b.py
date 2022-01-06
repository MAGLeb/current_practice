# from collections import Counter

def invert(s):
    res = ''

    for let in s:
        if let == '1':
            res += '0'
        else:
            res += '1'

    return res


# def difference(s_1, s_2):
#     diff = ''

#     for lett_1, lett_2 in zip(s_1, s_2):
#         if lett_1 != lett_2:
#             diff += '1'
#         else:
#             diff += '0'

#     return diff


# def solution():
#     m = input()

#     s_1 = input()
#     s_2 = input()

#     while s_1 != s_2:
#         diff = difference(s_1, s_2)
#         index = diff.rfind('1') + 1
#         cnt = Counter(s_1[:index]).most_common()

#         if len(cnt) != 2 or (len(cnt) == 2 and cnt[0][1] != cnt[1][1]):
#             return False

#         s_1 = invert(s_1[:index]) + s_1[index:]

#     return True


def solution():
    m = input()

    s_1 = input()
    s_2 = input()

    c_0 = 0
    c_1 = 0
    curr_i = 0
    res = ''

    for i in range(len(s_1)):
        curr_v = s_1[i]

        if curr_v == '0':
            c_0 += 1
        else:
            c_1 += 1

        if curr_v != s_2[i]:
            if c_0 != c_1:
                return False
                
            res += invert(s_1[curr_i:i])
            curr_i = i
    
    
            









n = int(input())

for _ in range(n):
    if solution():
        print('YES')
    else:
        print('NO')



    