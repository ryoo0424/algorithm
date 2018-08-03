import sys
print(sys.argv)

import os
print(os.environ)
print(os.getcwd())

import time
print(time.time())
print(time.localtime(time.time()))
print(time.asctime(time.localtime(time.time())))
print(time.ctime()) # 인수가 없으므로 항상 현재 시간만을 리턴
print(time.strftime('%x', time.localtime(time.time())))
for i in range(10):
    print(i)
    # time.sleep(.1)

import calendar
print(calendar.calendar(2015))
print(calendar.weekday(2015, 12, 31))
print(calendar.monthrange(2018, 12))

import random
print(random.random())
print(random.randint(1, 10))

data = [1, 2, 3, 4, 5, 6, 7]
random.shuffle(data)
print(data)
def rand_pop(data):
    number = random.choice(data)
    data.remove(number)
    return number

while(data):
    print(rand_pop(data))

import webbrowser as wb
#wb.open("http://google.com")

from collections import namedtuple as nt

from collections import defaultdict as dd
a = "Life is too short. You need python."
d = dd(int)
# d라는 defaultdict 객체의 디폴트 값이 int라는 의미
# 따라서 d에 해당 키값이 없을 경우 자동으로 int의 초기값인 0이 저장

for c in a:
    d[c] += 1
print(d.items())

s = [('a', 100), ('b', 200), ('c', 300), ('a', 150), ('c', 120)]
d2 = dd(list)
for k, v in s:
    d2[k].append(v)
print(d2.items())
# 이렇게 하면 빈 리스트 값으로 초기화

# Q5
def lotto():
    i = 6
    while i > 0:
        nums = list(range(1, 46))
        num = random.choice(nums)
        nums.remove(num)
        print(num, end=" ")
        i-=1

lotto()

# Q5 - sol
res = []
while len(res) < 6:
    num = random.randint(1, 45)
    if num not in res:
        res.append(num)

print(res)

# Q6
class Student:
    def __init__(self, name, score):
        self.name = name
        self.score = score

a = Student("aa", 30)

from collections import namedtuple as nt
ab = nt("Student", ["name", "score"])
abc = Student("aa", 30)
print(abc.name, abc.score)
