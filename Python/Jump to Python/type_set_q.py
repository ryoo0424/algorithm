# Q1
s1 = set(['a', 'b', 'c'])
print(s1)

# Q2
c = [1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5]
print(set(c))

# Q3
s1.update(['d', 'e'])
s2 = set(['c', 'd', 'e', 'f', 'g'])
print(s1 - s2); print(s1.difference(s2))

# Q4
a = {'a', 'b', 'c'}
print(a)
print(type(a))

b = set([])
print(type(b))

# Q5
a.update(['d', 'e', 'f'])
print(a)