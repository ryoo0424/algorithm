a = {'Name': 'Ryoo', 'Phone': '01044530424'}
a['Age'] = 27
for key in a:
    print(key, end=": "); print(a[key])

del a['Name']
for key in a:
    print(a[key])

# 딕셔너리의 key에 리스트는 쓸 수 없지만 튜플은 사용 가능
# key는 변하지 않는 값으로 설정해야 하므로 튜플은 올 수 있음

print(a.keys())
print(a.values())
print(a.items())
print(a.get('Age'))
print(a.get('Name', 'Default'))
print('Name' in a)
print('Phone' in a)
keys = list(a.keys())
print(keys)

a.clear(); print(a)

