def tot(a, b):
    return a + b


def safe_tot(a, b):
    if type(a) != type(b):
        print("Invalid input")
        return
    else:
        return sum(a, b)


# 아래의 구문이 없는 경우 내부 구문이 자동 실행
if __name__ == "__main__":
    print(safe_tot('a', 1))
    print(safe_tot(1, 4))
    print(tot(10, 10.4))
