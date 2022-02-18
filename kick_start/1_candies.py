from sys import stdin, stdout

n = int(stdin.readline().strip())

for i in range(1, n+1):
    bg, ch = list(map(int, stdin.readline().strip().split(' ')))
    candies = list(map(int, stdin.readline().strip().split(' ')))
    sum_candies = sum(candies)
    ans = sum_candies % ch
    stdout.write(f'Case #{i}: {ans}\n')
