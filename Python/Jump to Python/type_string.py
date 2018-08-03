def sum(_a, _b):
    return _a+_b


for a in [1, 2, 3]:
    print(a)

print(sum(3, 4))

"""
multi-line comment
"""
# single-line comment

print(105**3) # 지수승
print(105//4) # 소수점 아래를 버림
print(-105//4) # 정확히는 나눈 수보다 작은 수 중 최댓값 반환

print(17//3)
print(17%3)

if 17%2 == 0:
    print("even")
else:
    print("odd")

ml = "Life is too short\nPython is needed"
mml ="""\
Life is too short
You need python
"""
print(mml + "mml")

print(ml)

head = "python"
tail = " is easy"
print(head + tail)

print("=" * 50)
print("My program")
print("=" * 50)

print(ml[-1]) # 맨 뒤에서부터 거꾸로 인덱싱
print(ml[0:4])
print(ml[10:])
print(ml[10:-5])

number = 10
fruit = 'apples'
form = "I eat %d %s" % (number, fruit)
date = 3
print(form)

string = "I ate {0} apples. So i was sick for {1} days."\
    .format(number, date)
print(string)

string2 = "number = {0}, day = {day}".format(number, day=date)
print(string2)

# 왼쪽 정렬
str3 = "{0:<10} << left".format("hi")
str4 = "{0:>10} << right".format("hi")
str5 = "{0:^10} << center".format("hi")
str6 = "{0:!<10} << fill in whitespace".format("hi")
print(str3 + "\n" + str4 + "\n" + str5 + "\n" + str6)

print(string.count('a'))
print(string.find('a'))
a = "="
print(a.join(string))
print(string.upper())
print(string.lower())

print(string.replace("ate", "buried"))
print(string.split())
a = "a:b:c:d"
print(a.split(":"))

print(string.find("So"))
print(a.replace(":", "#"))

# remove whitespace
tmp = " Hi "
print(tmp.lstrip())
print(tmp.rstrip())
print(tmp.strip())