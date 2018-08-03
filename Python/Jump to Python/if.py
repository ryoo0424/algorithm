score = 70
message = "pass" if score >= 60 else "fail"

# Q1
money = 5000; card = False
taxi = "Yes" if money >= 4000 or card else "No"
print(taxi)

# Q2
l = [1, 9, 23, 46]
print("Y") if 23 in l else ""

# Q3
given = 35
print("even") if given % 2 == 0 else print("odd")

# Q4
string = "나이:30, 키:180"
age = int(string[string.index("나이")+3:string.index("나이")+5])
height = int(string[string.index("키")+2:string.index("키")+5])
print("YES") if age < 30 or height >= 175 else print("NO")
