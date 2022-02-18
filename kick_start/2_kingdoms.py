from sys import stdin, stdout


def get_ruler(kingdom):
    vowels = {'a', 'e', 'i', 'o', 'u'}
    last_letter = kingdom[-1].lower()

    if last_letter == 'y':
        return 'nobody'
    elif last_letter in vowels:
        return 'Alice'
    else:
        return 'Bob'


def main():
    n = int(stdin.readline())

    for i in range(n):
        kingdom = stdin.readline().strip()
        ruler = get_ruler(kingdom)
        stdout.write(f'Case #{i+1}: {kingdom} is ruled by {ruler}.\n')


if __name__ == '__main__':
    main()
