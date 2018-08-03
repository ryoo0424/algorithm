class Calculator:
    def __init__(self, first=0, second=1):
        self.first = first
        self.second = second

    def add(self):
        return (self.first + self.second)

    def mul(self):
        return (self.first * self.second)

    def dif(self):
        return (self.first - self.second)

    def div(self):
        return (self.first / self.second)


a = Calculator()
print(a.div())

class AddedCal(Calculator):
    def sqr(self):
        return (self.first ** self.second)

b = AddedCal(10312, 3)
print(b.add())
print(b.sqr())

print(b.add, a.add)

class ClassVar:
    static_var = "static"

c = ClassVar()
d = ClassVar()
print(id(c.static_var), id(d.static_var))
# 동일한 클래스의 인스턴스는 클래스 변수를 공유함(static)