# first = str(input())[::-1]
# second = str(input())[::-1]

first = '1011110'[::-1]
second = '1011110'[::-1]

diff = len(first) - len(second)

if(diff < 0):
  first += '0'*(abs(diff))
elif(diff > 0):
  second += '0'*(diff)

result = []
counter = 0

for i in range(len(first)):
  if(int(first[i]) == 0):
    if(int(second[i]) == 0):
      if(counter == 1):
        result.append(1)
      else:
        result.append(0)
      counter = 0
    else:
      if(counter == 1):
        result.append(0)
      else:
        result.append(1)
  else:
    if(int(second[i]) == 0):
      if(counter == 1):
        result.append(0)
      else:
        result.append(1)
    else:
      if(counter == 1):
        result.append(1)
      else:
        result.append(0)
        counter = 1

if(counter != 0):
  result.append(1)


print('My algorithm:', ''.join(str(item) for item in result)[::-1])

print('Use pth func:', bin(int(first[::-1], 2) + int(second[::-1], 2))[2:])