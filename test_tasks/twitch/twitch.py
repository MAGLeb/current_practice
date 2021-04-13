def z_function(s, length):
    n = len(s)
    z = [0 for _ in range(n)]
    l, r, k = 0, 0, 0
    for i in range(1, n):
        if i > r:
            l, r = i, i
            while r < n and s[r - l] == s[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:
            k = i - l
            if z[k] < r - i + 1:
                z[i] = z[k]
            else:
                l = i
                while r < n and s[r - l] == s[r]:
                    r += 1
                z[i] = r - l
                r -= 1
    for index, value in enumerate(z):
        if value != length:
            z[index] = 0

    return z[length + 1:]


def solution(min_cheermote_amount, valid_cheermotes, messages):
    messages = messages.split(',')
    total_result = {}

    for message in messages:
        result = {}

        for word in valid_cheermotes:
            indexes_of_start_cheermote = z_function(word + '#' + message, len(word))

            # find number after cheermote
            for i, index in enumerate(indexes_of_start_cheermote):
                if index != 0:
                    number = '0'
                    for letter in message[i + index:]:
                        if letter.isdigit():
                            number += letter
                        else:
                            break

                    number = int(number)

                    if number > 10000:
                        result = {}
                        break
                    if number >= min_cheermote_amount:
                        # accumulate cheermote value in one message
                        if word in result:
                            result[word] += number
                        else:
                            result[word] = number

        # filter cheermote more than 100k
        for key in list(result.keys()):
            value = result[key]
            if value > 100000:
                del result[key]
                continue
            if key in total_result:
                total_result[key] += value
            else:
                total_result[key] = value

    answer = []
    if total_result:
        sorted_total_result = sorted(total_result.items(), key=lambda x: x[1], reverse=True)
        for key, value in sorted_total_result:
            answer.append(key + str(value))
    else:
        answer.append('NO_CHEERS')

    return answer
