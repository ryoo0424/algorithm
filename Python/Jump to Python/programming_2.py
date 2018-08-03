def tot(limit):
    result = 0
    i = 1
    while i <= limit:
        if i % 3 == 0 or i % 5 == 0:
            result += i
        i += 1
    print(result)

tot(1000)
