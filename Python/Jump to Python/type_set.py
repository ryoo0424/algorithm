s1 = set([1, 2, 3])
print(s1)

s2 = set("Hello")
print(s2)

# 집합: 중복 x, 순서 없음(-> 인덱싱 불가)
# 자료형의 중복을 제거하기 위한 필터로 종종 사용함

l1 = list(s1)
print(l1[1])

t1 = tuple(s1)
print(t1[2])

s3 = set([1, 2, 3, 4, 5, 6])
s4 = set([4, 5, 6, 7, 8])
# intersection
print(s3 & s4)
print(s3.intersection(s4))
# union
print(s3 | s4)
print(s3.union(s4))
# difference
print(s3 - s4)
print(s3.difference(s4))
# add
s3.add(10) # 값 하나 추가하기
s3.update([11, 12, 13]) # 여러 값 추가하기
print(s3)
# remove
s3.remove(13)
print(s3)

