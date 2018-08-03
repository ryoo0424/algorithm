from copy import copy
a = [1, 2, 3]
print("%x" % id(a))

b = a

print(a is b)
print("%x" % id(b))

# 리스트 복사 방법
# 1. [:]: 리스트 전체를 의미하는 [:]를 이용
c = a[:]
c.append(10)
print(c); print(a)

#2. copy 모듈 이용
b = copy(a)
b.append(123)
print(b); print(a)

# 변수 만드는 방법
x, y = ('this is x', 'this is y')
print(x + "\t" + y)

# swap
x, y = y, x
print(x + "\t" + y) # ...

tmp = [1, 2, 3]
print(type(tmp + [4, 5]))
tmp2 = [4, 5]
print(tmp + [4, 5] is tmp.extend(tmp2))
print(type(tmp))
