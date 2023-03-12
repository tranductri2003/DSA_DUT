from collections import defaultdict
check = defaultdict(lambda: 0)

n = int(input())
data = []
for _ in range(n):
    temp = int(input())
    check[temp] += 1
    data.append(temp)
#     data.append(((len(str(temp))), temp))

# data.sort(key=lambda x: x[0])

stop = False
for num in data:
    for i in range(0, len(str(num))):
        if i == len(str(num))-1:
            if check[num] > 1:
                stop = True
        else:
            if check[int(str(num)[:i+1])] != 0:
                stop = True

print(1) if stop == False else print(0)
