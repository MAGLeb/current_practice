# ### TESTING
#
# dictionary = {}
# array = [(10, 10, 0), (10, 20, 1), (20, 10, 2), (10, 20, 3), (10, 20, 4), (10, 10, 5), (20, 10, 6)]
# n = len(array)
#
#
# for pair in array:
#     if pair[0] == pair[1]:
#         if pair[0] not in dictionary:
#             dictionary[pair[0]] = [pair]
#         else:
#             dictionary[pair[0]] += [pair]
#     else:
#         for x in pair[:2]:
#             if x not in dictionary:
#                 dictionary[x] = [pair]
#             else:
#                 dictionary[x] += [pair]
#
# print(dictionary)
#
#
# for key, value in dictionary.items():
#     dictionary[key] = len(value)
#
#
# print(dictionary)
#
#
#
#
#
a = [(10, 10, 0), (10, 20, 1), (20, 10, 2), (10, 20, 3), (10, 20, 4), (10, 10, 5), (20, 10, 6)]
# # a = [(3, 2, 0), (2, 2, 1), (5, 5, 2), (3, 5, 3), (4, 3, 4)]
#
# print(a[::-1])
#
# ans = 0
#
# for el in a[::-1]:
#     if el[0] == el[1]:
#         dictionary[el[0]] -= 1
#         ans += dictionary[el[0]]
#         continue
#
#     dictionary[el[0]] -= 1
#     dictionary[el[1]] -= 1
#     ans += dictionary[el[0]]
#     ans += dictionary[el[1]]
#
# print(ans)
# print(dictionary)
print("\n" * 5)
print("HERE")

ans = 0
d = {}
for el in a[::-1]:
    for j, key in enumerate([el[0], el[1]]):
        if j == 1 and el[0] == el[1]:
            continue
        if key in d:
            ans += d[key]
            d[key] += 1
        else:
            d[key] = 1
        if j == 1:
            key = tuple(sorted(el[:2]))
            if key in d:
                ans -= d[key]
                d[key] += 1
            else:
                d[key] = 1

print(d)
print(ans)
