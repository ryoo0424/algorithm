import re

data = """python one
life is too short
python two
you need python
python three"""

p = re.compile('python')
print(p.match(data).group())

p = re.compile('[c{2, 7}a*tb+z?ti\[.\]b.bb^g]')
print(list(p.findall(data)))

m = re.match('[a-z]+', "python")

p = re.compile('[a.b]', re.DOTALL)
print(p.match('a\nb'))

p = re.compile("^python\s\w+", re.M)
print(p.findall(data))

p = re.compile(r'\\section')

p = re.compile('Crow|Servo', re.I)
m = p.match("crowhello")
print(m.group())

p = re.compile(r"(\w+)\s+((\d+)[-]\d+[-]\d+)")
m = p.search("Ryoo 010-0000-0000")
print(m.group(0))
print(m.group(1), m.group(2))
print(type(m.group(2)))

# grouping된 문자열 재참조 by \1: 1번 그룹과 동일한 단어
p = re.compile(r'(\b\w+)\s+\1')
print(p.search('Paris in the the spring').group())

# 인덱스로 그룹을 찾을 때 문제가 발생할 수 있기 때문에 그룹에 이름 필요
p = re.compile(r"(?P<name>\w+)\s+((\d+)[-]\d+[-]\d+)")
print(p.search("ryoo 010-0000-0000").group("name"))

# 재참조 할 때
p = re.compile(r'(?P<word>\b\w+)\s+(?P=word)')
print(p.search('Paris in the the spring').group())

# 전방 탐색 - 긍정(?=) / 부정(?!)
p = re.compile(".+(?=:)")
m = p.search("http://google.com")
print(m.group())
# (.*[.](?!bat$|?!exe$).*$): .bat, .exe만 제외..

# 문자열 바꾸기
p = re.compile("(blue|red|white)")
print(p.sub("colour", "blue sky and red beef with white wine"))
# 아래는 결과물과 변경 횟수를 튜플로 리턴해줌
print(p.subn("colour", "blue sky and red beef with white wine"))

# sub 사용 시 참조 구문 사용하기
p = re.compile(r"(?P<name>\w+)\s+(?P<phone>\d+[-]\d+[-]\d+)")
print(p.sub("\g<phone> \g<name>", "Ryoo 010-4453-0424"))
print(p.sub("\g<2> \g<1>", "Ryoo 010-4453-0424"))

# sub 메소드의 입력 인수로 함수 넣기
def hexRepl(match):
    value = int(match.group())
    return hex(value)
# sub의 첫 번째 인수로 함수를 사용할 경우 해당 함수의 첫 번째 입ㄺ에 정규식과 매치된 match 객체가 입력됨
p = re.compile(r'\d+')
print(p.sub(hexRepl, 'Call 65490 for printing, 49152 for user code.'))

# greedy vs non-greedy
s = '<html><head><title>Title</title></head></html>'
print(re.match('<.*?>', s).group())
# *만 쓰면 문자열 전체를 소모해버리지만 ?로 이를 제한

