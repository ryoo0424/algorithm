a = range(10)
print(a)

tot = 0
for i in a:
    tot += i

cut = 55
mark = [90, 25, 67, 45, 80]
for num in range(len(mark)):
    if mark[num] > cut:
        print("%d: pass" % (num + 1))

for i in range(2, 10):
    for j in range(1, 10):
        print("%2d" % (i * j), end=" ")
    print("")

result = [num // 2 for num in mark]
print(result)

result = [num ** 1.5 for num in mark if num % 2 == 0]
print(result)

result.append([x*y for x in range(2,10) for y in range(1,10)])
print(result)
print(result[2])

# Q4
bt = ['A', 'B', 'A', 'O', 'AB', 'O', 'A', 'B', 'O', 'B', 'AB']
result = {}
for blood in bt:
    if blood in result:
        result[blood] += 1
    else:
        result[blood] = 1
print(result)

nums = [1, 2, 3, 4, 5]
result1 = [nums ** 2 for nums in nums if nums % 2 == 1]
print(result1)

# 왜 이건 안되지..
string = 'Life is too short. You need python.'
checker = 'aeiou'
string2 = ''
string2.join([a for a in string if a not in checker])
print(string2)

vowels = 'aeiou'
sentence = 'Life is too short. You need python.'
print(''.join([a for a in sentence if a not in vowels]))
