'''
f = open("new_text.txt", "w")
f.close()
# r: read, w: write, a:append(파일의 마지막에 내용 추가)
'''
# 파일에 쓰기
f = open("C:/Users/fbwjd/Desktop/Coding/Python/new.txt", 'w')
for i in range(1, 11):
    data = i
    f.write(str(data))
    f.write("\n")
f.close()
# 파일 한 줄 읽기
f = open("C:/Users/fbwjd/Desktop/Coding/Python/new.txt", 'r')
while True:
    line = f.readline()
    if not line: break
    print(line, end="")
f.close()
# 전체를 리스트로 받아 읽기
f = open("C:/Users/fbwjd/Desktop/Coding/Python/new.txt", 'r')
lines = f.readlines()
for line in lines:
    print(line, end="")
print(lines)
f.close()
# 파일 전체를 문자열로 리턴
f = open("C:/Users/fbwjd/Desktop/Coding/Python/new.txt", 'r')
data2 = f.read()
print(data2)
f.close()
# 자동으로 close()하기
with open("C:/Users/fbwjd/Desktop/Coding/Python/new.txt", 'w') as f:
    f.write("Life")

import sys

args = sys.argv[1:]
for i in args:
    print(i)