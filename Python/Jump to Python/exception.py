# try, except clause
'''
try:
    ...
except [error[as err variable]]:
    ...
# [] 기호는 괄호 안의 내용을 생략할 수 있다는 관례적 표현
'''
# 1.
try: 4/0
except ZeroDivisionError as e:
    print(e)

# 2.
try:
    f = open('foo.txt', 'r')
except FileNotFoundError as e:
    print(str(e))
else:
    data = f.read()
    f.close()
# foo.txt 파일이 없다면 except절이 수행, 있다면 else 절이 수행됨

# 3.
f = open('foo.txt', 'w')
try:
    pass
finally:
    f.close()
# finally 절은 try문 수행 도중 예외 발생 여부에 상관없이 항상 수행됨
# 보통 사용한 리소스를 close해야 할 경우에 많이 사용됨

# 4. 복수의 오류 처리
"""
try:
    pass
except 오류 1:
    ...
except 오류 2:
    ...
...
"""
try:
    a = [1, 2]
    print(a[2])
    4/0
except ZeroDivisionError: print("Invalid division")
except IndexError: print("Invalid index")

try:
    a = [1, 2]
    print(a[2])
    4/0
except ZeroDivisionError as e: print(e)
except IndexError as e: print(e)

try:
    a = [1, 2]
    print(a[2])
    4/0
except (ZeroDivisionError, IndexError) as e:
    print(e)

# 5. 프로그래밍 도중 오류 발생 시 그냥 통과시켜야 할 때
try:
    f = open("no file.txt", 'r')
except FileNotFoundError: pass

# 6. 강제로 오류 발생시키기: raise
class Bird:
    def fly(self):
        raise NotImplementedError
        # Bird를 상속받는 클래스는 반드시 fly 메소드를 구현해야 함

class Eagle(Bird):
    pass

eagle = Eagle()
#eagle.fly()

# 7. 예외 만들기
class MyError(Exception):
    def __init__(self, msg):
        self.msg = msg

    def __str__(self):
        return "not allowed"

def say_nick(nick):
    if nick == 'example':
        raise MyError()
    print(nick)

# say_nick('example')

try:
    say_nick("first")
    say_nick("example")
except MyError as e:
    print(e)
    print("Invalid nickname")