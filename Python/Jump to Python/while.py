prompt = """
1. Add
2. Del
3. List
4. Quit
    
Enter number:
"""
# Q3
a = [20, 55, 67, 82, 45, 33, 90, 87, 100, 25]
tot = 0
while a:
    if a[-1] >= 50:
        tot += a[-1]
    a.pop()

print(tot)

# Q5
k = 4
while k > 0:
    print("{0:^7}".format("*"*((k*2) - 1)))
    k -= 1
