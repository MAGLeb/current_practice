# n = int(input())

# for _ in range(n):
#     find = False
#     s = list(input())

#     for i in range(len(s)):
#         new_s = s.copy()
#         new_s.insert(i, 'a')

#         if new_s != new_s[::-1]:
#             find = True
#             break
    
#     if find:
#         print('YES')
#         print(''.join(new_s))
#     else:
#         print('NO')

### SECOND SOLUTION

# def is_palidrom(s):
#     if s == 'a':
#         return True
#     elif len(s) == 1:
#         return 'a' + s

#     flag = False
#     i = 0
#     j = len(s) - 1

#     while i < j: 
#         if s[i] != s[j]:
#             if flag:
#                 return s[:i] + 'a' + s[i:]
#             if s[i] == 'a':
#                 j -= 1
#                 flag = True
#             elif s[i] == 'a':
#                 i += 1
#                 flag = True
#             else:
#                 return s[:i] + 'a' + s[i:]
#         else:
#             j -= 1
#             i += 1

#     if flag:
#         return True
#     else:
#         if len(s) % 2 == 0:
#             return True

#         if s[int(len(s) / 2) + 1] == 'a':
#             return True
#         else:
#             return 'a' + s


# n = int(input())

# for _ in range(n):
#     s = input()

#     answer = is_palidrom(s)

#     if isinstance(answer, str):
#         print('YES')
#         print(answer)
#     else:
#         print('NO')

##### THIRD SOLUTION

from collections import Counter
n = int(input())
answer = None

for _ in range(n):
    s = input()
    
    for i, letter in enumerate(s):
        if letter != 'a':
            n_s = 'a' + s
            answer = s + 'a' if n_s == n_s[::-1] else n_s
            break
    
    if answer is None:
        print('YES')
        print(answer)
    else:
        print('NO')

