# Q1
a = "Life is too short you need python"

b = a.split()

print(b.index("you"))
print(b.index("too"))
print(b[4] + " " + b[2])

# Q2
c = b[0:4]
for i in c:
    print(i, end=" ")
print(" ")

# Q3
d = [1, 2, 3]
print(len(d))

# Q4
d1 = [1, 2, 3]
d2 = [1, 2, 3]
e = [4, 5]
d1.extend(e); print(d1) # extend는 말 그대로 확장
d2.append(e); print(d2) # append는 말 그대로 갖다 붙임

# Q5
f = [1, 3, 5, 4, 2]
f.sort(); print(f)
f.reverse(); print(f)

# Q6
g = [1, 2, 3, 4, 5]
g.remove(2); g.remove(4); print(g)
# or del g[1]; del g[3]

