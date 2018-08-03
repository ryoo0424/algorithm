a = [1, 2, 3, ['a', 'b', 'c']]

print(a)
print(a[-1][0])
print(a[1:])
print(a[-1][:-1]) # ??

a[1:3] = [] # delete list
print(a)

a[1:2] = ['a', 'b', 'c']
print(a)

del a[1]
print(a)

a.append(10)
print(a)
a.reverse()
print(a)

print(a.index(10))

a.insert(0, 123) # 0번 인덱스에 123 추가
print(a)
a.pop() # 맨 뒤 숫자를 뺀다
print(a)
a.remove(123)
print(a)

print(a.count(12312))
b = [6, 7]
c = a
print(a + b)
print("a = ", end=""); print(a)

c.append(b)
print("c = ", end=""); print(c)
print(b)

a.extend(b)
print(a)

c.extend(b)
print(c)
# 리스트를 이런식으로 복사하면 이름만 다르고 같은 리스트를 공유..왜?

aa = 10
bb = aa
bb -= 3
print(aa)
# 얘는 또 안이러네..?