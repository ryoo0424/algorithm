"""
abs(): 절댓값 반환 함수
all(): 반복 가능한 자료형 x를 인수로 받아
       인수의 모든 요소가 참이면 True, 하나라도 거짓이면 False 반환
       ex>> all([1, 2, 3, 4, 0]) == False
any(): 하나라도 참이면 True, 전부 거짓일 경우 False
chr(): ASCII CODE를 입력 받아 해당 문자로 변환해주는 함수
dir(): 객체가 자체적으로 가지는 변수나 함수를 보여줌
       리스트, 딕셔너리, 튜플 등이 가지는 메소드 파악할 때 쓰면 될 듯
divmod(a, b): a//b와 a%b를 튜플 형태로 리턴
enumerate(): 순서가 있는 자료형(리스트, 튜플, 문자열)을 입력받아
             인덱스 값을 포함하는 enumerate 객체 리턴
             ex>> for i, name in enumerate(['a', 'b', 'c'])
                    print(i, name)
eval(expression): 실행 가능한 문자열(1+2, 'hi'+'a')을 입력받아
                  문자열을 실행한 결과값을 리턴
                  ex>> eval('1+2'); eval('divmod(4, 3)')
filter(): 첫 번째 인수로 함수 이름을, 두 번째 인수로 해당 함수에
          차례로 들어갈 iterable 자료형을 받는다. 자료형이 함수에
          입력되었을 때 리턴값이 참인 것만 걸러내서 돌려줌
          ex>> def postive(x):
                   return x > 0
               print(list(filter[positive, [1, -3, 0, 2])
          ex>> print(list(filter(lambda x: x > 0, [1, -3, 0, 2])
hex(): integer를 입력받아 16진수로 변환하여 리턴
id(): 객체의 주소값 리턴
input()
int(x) or int(x, radix)
isinstance(object, class): 해당 객체가 해당 클래스의 인스턴스인지
len()
list()
map(function, iterable): 입력받은 자료형의 각 요소가 입력 함수에 의해
                         수행된 결과를 묶어서 리턴하는 함수
max(), min()
oct(): integer를 8진수 문자열로 바꿔 리턴하는 함수
open(): 'w'-write, 'r'-read, 'a'-append, 'b'-binary
        default가 'r'이다.
ord(): 문자의 ASCII CODE 값을 리턴 <--> chr()
pow()
range(x)-0 ~ x-1 or range(first, last(-1))
or range(first, last, interval)'
round(): 반올림 or round(x, y) x를 소수점 y번째 자리까지 반올림
         ex>> round(5.678, 2) - 5.68
sorted(iterable): 정렬하여 리턴
                  cf>> sort()는 리턴값이 없다
str(): 문자열로 변환
tuple()
type()
zip(): 동일한 수로 이루어진 n개의 자료형을 묶어줌
       ex>> list(zip([1, 2, 3], [4, 5, 6]))
       >> [(1, 4), (2, 5), (3, 6)]
       ex>> list(zip([1, 2], [3, 4], [5, 6]))
       >> [(1, 3, 5), (2, 4, 6)]
"""
# Q2
d = dict()
for i, name in enumerate(['a', 'b', 'c']):
    d[i] = name
print(d)

# Q3
del_list = list(filter(lambda x: x > 0, [1, -2, 3, -5, 8, -3]))
print(del_list)

# Q4
print(int(0xea))

# Q5
print(list(map(lambda x: x*3, [1, 2, 3, 4])))

# Q6
li = [-8, 2, 7, 5, -3, 5, 0, 1]
print(max(li) + min(li))

# Q7
print(round((17 / 3), 4))

# Q8
print(list(zip([1, 2, 3, 4], ['a', 'b', 'c', 'd'])))
