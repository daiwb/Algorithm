mm = [1, 11, 21, 1211, 111221]

while len(mm) < 31:
    result = ''
    resultlist = []
    a = str(mm[-1])

    num = 0
    prev = 'z'
    next = ''

    for i in range(0, len(a)):
        now = a[i]

        if now == prev:
            num += 1
        else:
            if num > 0:
                next += str(num)
                next += prev

            num = 1
            prev = now

    next += str(num)
    next += prev

    #print(next)

    mm.append(int(next))

print(len(str(mm[30])))
