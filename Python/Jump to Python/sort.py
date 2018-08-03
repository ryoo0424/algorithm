# 딕셔너리에 sorted를 적용하면 딕셔너리의 키값들을 정렬하여 리턴
students = [
    ("Jane", 22, "A"),
    ("Dave", 32, "B"),
    ("Sally", 17, "O")
]
# 위와 같이 튜플이 셋 이상인 경우 람다(or 함수)를 이용하여 key를 지정해야 함
print(sorted(students, key=lambda x: x[1]))

class Student:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade
    # repr은 Student 클래스에 의해 생성된 객체의 정보를 출력할 때 씀
    def __repr__(self):
        return repr((self.name, self.age, self.grade))

student = Student("Jane", 22, "A")
print(student.name)
print(student)

student_object = [
    Student("Jane", 22, "A"),
    Student("Dave", 32, "B"),
    Student("Sally", 17, "O")
]

result = sorted(student_object, key=lambda x: x.grade)
print(result)

# key 함수에 lambda 대신 operator 모듈을 이용하는 방법
from operator import itemgetter as ig

result = sorted(students, key=ig(1))
print(result)

from operator import attrgetter as ag

result = sorted(student_object, key=ag('name'), reverse=True)
print(result)

# 중첩 정렬 - 기준이 두개
"""
정렬 기준 1 - 성적, 2 - 나이
--> 나이 기준으로 먼저 하고 성적으로 하면 원하는 결과 나옴
"""
