# 파라미터 수가 정해져있지 않은 함수도 만들 수 있다
def sums(*args):
    tot = 0
    for i in args:
        tot += i
    return tot

def selective(flag, *args):
    if flag == 's':
        result = 0
        for i in args:
            result += i
    elif flag == 'm':
        result = 1
        for i in args:
            result *= i
    return result

# **kwagrs는 모든 key=value 형태의 입력변수가 저장되는 딕셔너리 인수
def func(*args, **kwargs): 
    print(args)
    print(kwargs)

def sum_mul(a, b):
    return a+b, a*b

# 1. 초기값을 설정할 인수는 항상 맨 뒤에 둬야 함
# 2. 아래와 같은 인수를 받을 경우(**) 그 뒤에 인수를 추가할 수 없음
# ** 아래의 함수는 예시일 뿐 올바르게 선언된 함수가 아님
def f2(flag=1, *args, **kwargs):
    if not flag:
        return
    else:
        print(args)
        print(kwargs)



print(sums(1, 2, 3, 4, 1, 2))
# 매개변수 명 앞에 *를 붙이면 입력 값들을 전부 모아 튜플로 만들어 줌

print(selective('s', 1, 2, 3, 4))

func(name='foo', age=3)

func(1, 2, 3, name='foo', age=3)

a = sum_mul(10, 2193)
print(type(a[0]))

f2(1, 'A', 'B', Phone='010', Name='ryoo')

aa = 1
# 1. global: C에서의 전역변수처럼 사용할 것임을 밝힘
# 2. 하지만 권장되지는 않는 방법임
def vartest():
    global aa
    aa += 1

vartest()
print(aa)

# lambda
# 1. def를 사용해야 할 정도로 복잡하지 않거나
# 2. def를 사용할 수 없는 곳에 주로 사용
sum2 = lambda a, b: a + b
print(sum2(3, 4))

myList = [lambda a,b: a+b, lambda a,b: a*b]
print(myList)

# 람다의 인수로 (3, 4)를 넣었을 때 리스트의 0, 1을 각각 출력
print("[0]: %d, [1]: %d" % (myList[0](3, 4), myList[1](3, 4)))

