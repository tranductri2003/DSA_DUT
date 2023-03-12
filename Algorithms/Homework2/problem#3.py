def func(n):
    r = 0
    for i in range(1, n):
        for j in range(i+1, n):
            for k in range(1, j):
                r += 1
    print(r)


for i in range(1, 11):
    func(i)
