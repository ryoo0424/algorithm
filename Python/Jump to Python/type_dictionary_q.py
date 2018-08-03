# Q1
dic = {'name': 'Hong', 'birth': '1128', 'age': 30}
print(dic.items())

# Q2
# error: 3 --> no list on key

# Q3
a = {'A': 90, 'B': 80, 'C': 70}
print(a.get('B'))
del a['B']
print(a)

# Q4
print(a.get('B', '70'))

# Q5
a['D'] = 60
tmp = 101
for key in a:
    if a[key] < tmp:
        tmp = a[key]
print(tmp)

# Q6
print(list(a.items()))