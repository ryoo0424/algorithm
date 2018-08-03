# Q1
class Cal:
    def __init__(self, init=0):
        self.value = init

    def add(self, val):
        self.value += val

c = Cal()
c.add(3); print(c.value)
c.add(4); print(c.value)

# Q2
# init_value의 초깃값을 설정하거나 생성자에 인수를 전달해야 함

# Q3
class UpCal(Cal):
    def sub(self, val):
        self.value -= val

d = UpCal()
d.add(20); print(d.value)
d.sub(10); print(d.value)

# Q4
class MaxCal(Cal):
    def add(self, val):
        if(self.value + val > 100):
            self.value = 100
        else:
            self.value += val

e = MaxCal(70)
e.add(34); print(e.value)

# Q5
class Cal2:
    def __init__(self, arr):
        self.ip = arr

    def tot(self):
        ret = 0
        for i in self.ip:
            ret += i
        return ret

    def avg(self):
        return (self.tot() / len(self.ip))

f = Cal2([1, 2, 3, 4, 5])
print(f.tot())
print(f.avg())

g = Cal2([6, 7, 8, 9, 10])
print(g.tot())
print(g.avg())