# Q1
with open("IO_file_q1.txt", "w") as f1:
    f1.write("Life is too short")

with open("IO_file_q1.txt", "r") as f2:
    print(f2.read())

# Q2
with open("IO_file_q2.txt", "a") as f3:
    ip = input("input: ")
    f3.write(ip+"\n")

# Q3
with open("IO_file_q3.txt", "r") as f4:
    li = f4.readlines()
for i in li:
    i.strip()
print(li)

with open("IO_file_q3.txt", "w") as f5:
    while li:
        f5.write(li[-1])
        li.pop()
