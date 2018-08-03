# Q3
a = "PYTHON"
print("{0:>30}".format(a))
print("{0:#>30}".format(a))

# Q4
cid = "881120-1068234"
print("19{year}-{month}-{date}-{rest}"\
      .format(year=cid[:2],\
              month=cid[2:4],\
              date=cid[4:6],\
              rest=cid[7:]))

# Q5
myd = "1980M1120"
print(myd.replace("1980M", "M1980"))

