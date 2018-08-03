# Q1
def func1(nat):
    if nat % 2 == 0: return 1
    else: return 0
# == Q1
is_odd = lambda x: True if x % 2 == 0 else False

# Q2
def func2(*args):
    tot = 0
    for i in args:
        tot += i
    return tot/len(args)

# Q3
def func3(num):
    for i in range(1, 10):
        print("%2d" % (num*i), end=" ")
print(func3(9))

# Q4
def func4(n):
    pibo = [0, 1]
    i = 0
    while i < n - 1:
        pibo[0], pibo[1] = pibo[1], (pibo[0]+pibo[1])
        i += 1
    return pibo[0]
print(func4(8))

# Q5
func5 = lambda ip: [op for op in ip if op > 5]
print(func5([3, 4, 5, 6, 7, 8]))
