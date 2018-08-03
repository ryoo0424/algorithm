"""
1. [a, b, c]: a, b, c 중 하나라도 일치하는 것이 있다면 참
2. [^a-c]: a, b, c와 매치되지 않는 것이 있다면 참
3. \d(숫자), \s(공백), \w(문자 + 숫자 = [a-zA-Z0-9)
4. .: \n을 제외한 모든 문자와 매치 -> [a.b] = "a + 모든 문자 + b"
** 단, 어떤 문자든 최소한 하나는 있어야 함
5. [a[.]b]: "a.b"를 매치시킴
6. *: 0번 이상 반복 가능 -> [ca*t]
7. +: 1번 이상 반복 가능
8. {n}, {n, m}: 반드시 n번 반복, n~m번 사이에서만 반복
9. ?: 0번 혹은 1번만
10. ^는 []라는 문자 클래스 안에서 사용될 때에만 not의 의미를 가짐
------------------------------------------------------------
1. match(), search(). findall(), finditer()
------------------------------------------------------------
1. re.DOTALL(=S), re.IGNORECASE(=I), re.MULTILINE(=M), re.VERBOSE(=X)
------------------------------------------------------------
1. ^: 문자열의 맨 처음과 일치함
2. &: 해당 문자열로 끝나는 경우 매치됨
3. \A: ^와 기능적으로 동일하나, re.M 옵션을 사용하는 경우 전체 문자열의 처음과만 매치됨
4. \Z: &와 기능적으로 동일하며 전체 문자열을 대상으로 하는 점만 다름
5. \b: 단어 구분자, 공백(whitespace)에 의해 구분 (r'\bclass\b')
** 원래 backspace를 의미하므로 반드시 string임을 알려주는 r기호가 필요
6. \B: 해당 문자열의 양 옆 모두 whitespace 없어야 함
7. (): grouping -> p = re.compile('(ABC)+')
** (r"\w+\s+\d+[-]\d+[-]\d+"): 이름 + " " + 전화번호
** 이름 부분만 뽑아내고싶다면 -> (r"(\w+)\s+\d+[-]\d+[-]\d+")
** search("ryoo 010-0000-0000"); print(m.group(1)) --> "ryoo"
** 0: 매치된 전체 문자열, 1: 첫 번째 그룹 문자열 ... n: n 번째 그룹
"""

import re

p = re.compile("[a-z]+")
m = p.match("python")
m2 = p.search("3 python")
print(m2)
result = p.findall("life is extremely 3 times too short")
print(result)

result = p.finditer("life is too short")
for r in result: print(r)
print(m.group())
print(m.start())
print(m.end())
print(m.span())

print(m2.span())

m3 = re.match('[a-z]+', "python")

# opt: re.DOTALL, re.I, re.M, re.X(=VERBOSE)
p = re.compile("^python\s\w+", re.MULTILINE)

data = """python one
life is too short
python two
you need python
python three"""

print(p.findall(data))

charref = re.compile(r'&[#](0[0-7]+|[0-9]+|x[0-9a-fA-F]+);')

charref = re.compile(r"""
 &[#]                # Start of a numeric entity reference
 (
     0[0-7]+         # Octal form
   | [0-9]+          # Decimal form
   | x[0-9a-fA-F]+   # Hexadecimal form
 )
 ;                   # Trailing semicolon
""", re.VERBOSE)

print(re.search('short$', 'life is too short').group())

