import re
from collections import defaultdict as dd

#Q1 이름 분석
names = ["이의덕", "이재명", "권종수", "이재수", "박철호", "강동희",\
         "이재수", "김지석", "최승만", "이성만", "박영희", "박수호",\
         "전경식", "송우환", "김재식", "이유정"]

p = re.compile("^김|^박")
cnt = dd(int)
for n in names:
    m = p.match(n)
    if m:
        cnt[m.group()] += 1
print("1-1: ", cnt)
ljs = 0
for n in names:
    if n == "이재수":
        ljs += 1
print("1-2: %d" % ljs)
print("1-3: ", set(names))
print("1-4: ", sorted(set(names)))

#Q2 합의 제곱과 제곱의 합의 차
def sqr_dif(num):
    sqr_sum = 0
    sum_sqr = 0
    for i in range(1, num+1):
        sqr_sum += i ** 2
        sum_sqr += i
    return (sum_sqr ** 2) - sqr_sum

print("2: %d" % sqr_dif(100))

#Q3 1부터 100까지의 각 숫자의 개수 구하기
num_cnt = dd(int)
for i in range(1, 101):
    for j in list(str(i)):
        num_cnt[j] += 1

print("3: ", dict(num_cnt))

#Q4 DashInsert ------------------------------------
ip = "21908475832741283782991029382"
isOdd = False
isEven = False
for i in range(0, len(ip)):
    if int(ip[i]) % 2 == 0:
        if isEven:
            ip = ip[:i] + "*" + ip[i:]
        else:
            isEven = True
            isOdd = False
    else:
        if isOdd:
            ip = ip[:i] + "-" + ip[i:]
        else:
            isEven = False
            isOdd = True

#Q5
string = "aaaaabbcbbbbcbaaaacbcaabcbcbbbcccabc"
def zip(s):
    char = s[0]
    cnt = 0
    ret = ""
    for k in range(0, len(s)):
        if s[k] == char:
            cnt += 1
        else:
            ret = ret + char + str(cnt)
            char = s[k]
            cnt = 1
    return ret

print("5: ", zip(string))

#Q6
numList = ["0123456789", "01234", "01234567890", "6789012345", "012322456789"]
def dup(s):
    result = []
    for num in s:
        if num not in result:
            result.append(num)
        else:
            return False
    return len(result) == 10

print("6: ", end="")
for s in numList:
    print(dup(s), end=" ")
print("")

#Q7
mos = ".... .  ... .-.. . . .--. ...  . .- .-. .-.. -.--"

def interpret(m):
    table = {".-": "A", "_...": "B", "-.-.": "C", "-..": "D", \
             ".": "E", "..-.": "F", "--.": "G", "....": "H", \
             "..": "I", ".---": "J", "-.-": "K", ".-..": "L", \
             "--": "M", "-.": "N", "---": "O", ".--.": "P", \
             "--.-": "Q", ".-.": "R", "...": "S", "-": "T", \
             "..-": "U", "...-": "V", ".--": "W", "-..-": "X", \
             "-.--": "Y", "--..": "Z"}
    m2 = m.split("  ")
    ret = ""
    for i in m2:
        tmp = i.split(" ")
        for j in range(0, len(tmp)):
            ret += table[tmp[j]]
        ret += " "
    return ret

print("7: ", interpret(mos))

#Q10 -----------------------------------------
s10 = """
park 010-9999-9988
kim 010-9909-7789
lee 010-8789-7768
"""
p = re.compile('(\d{3}[-]\d{4}[-])\d{4}')
m = p.sub("\g<1>####", s10)
print("10: ", m)

#Q11 -----------------------------------------
p = re.compile(".*[@].*[.](?:com$|net$).*$")

#Q14 -----------------------------------------
from operator import itemgetter as ig
students = [("홍길동", 22), ("김철수", 32), ("박영희", 17)]

print("14: ", sorted(students, key=ig(1)))

#Q15
cesar = ["CAT", "ZOO", "ASDJ", "JuliusX"]
