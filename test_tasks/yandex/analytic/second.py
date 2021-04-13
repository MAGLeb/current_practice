f = open('input.txt', 'r')
s = f.readline().strip()


def solution(string):
    hashmap = set()
    result = []

    start, end = (0, 1)

    while start < len(string):

        if end - start == 3:
            if string[0] == string[2] and string[1] == '0':
                result.append(string[:2])
                result.append(string[2])
                start = 3

        if string[start] == '0':
            if '0' not in hashmap:
                hashmap.add('0')
                result.append('0')
            start += 1
            end += 1

        substring = string[start: end]

        if end < len(string) and string[end] == '0':
            if end + 1 < len(string) and string[end + 1] != '0':
                # if end + end - start < len(string):

                if '0' not in hashmap:
                    if substring not in hashmap:
                        hashmap.add(substring)
                        result.append(substring)
                        start = end

                    hashmap.add('0')
                    result.append('0')

                end += 1
                continue
            else:
                if end == len(string) - 1 and '0' not in hashmap:
                    if substring not in hashmap:
                        hashmap.add(substring)
                        result.append(substring)
                        start = end

                    hashmap.add('0')
                    result.append('0')

                end += 1
                continue

        if substring and substring not in hashmap:
            hashmap.add(substring)
            result.append(substring)
            start = end

        if substring and end > len(string):
            result[-1] += substring
            break

        end += 1

    return result


first = solution(s)

print("-".join(first))
# sys.stdout.buffer.write("-".join(result).encode())
