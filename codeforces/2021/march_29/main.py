
def gcd(f, s):

    while True:
        if f % s == 0:
            return s

        r = s
        s = f - s * (f // s)
        f = r


def find_s(number):
    s = 0

    for letter in str(number):
        s += int(letter)

    return s


def solution():
    m = int(input())

    while True:
        m -= 1
        n = int(input())

        while True:
            result = gcd(n, find_s(n))

            if result > 1:
                print(n)
                break

            n += 1

        if m == 0:
            break


solution()
