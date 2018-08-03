import game.sound.echo as gse
import game.graphic.render as ggr
gse.echo_test()
ggr.render_test()

# 1. import game을 할 경우 game안의 __init__만 사용 가능
# 2. import를 통한 .의 마지막 항목은 반드시 모듈 또는 패키지여야 함
# ** 즉 game.sound.echo.echo_test와 같은 방식은 불가함

"""
# __init__.py의 용도
해당 디렉터리가 패키지의 일부임을 알려줌
망냑 game, sound, graphic 등의 패키지가 포함된 디렉터리에
해당 파일이 없다면 패키지로 인식되지 않음
(단, python3.3부터는 이 파일이 없어도 패키지로 인식됨
하지만 하위 버전 호환을 위해 생성해두는 것이 안전함)
"""

# from game.sound import *
# echo.echo_test() # --> error
# --> game/sound/__init__.py
# --> __all__ = ['echo']

"""
# __all__의 용도
sound 디렉터리에서 * 기호를 이용하여 import할 경우 이곳에 정의된
echo 모듈만 import 됨을 의미함
# __all__과 상관없이 무조건 import되는 경우는 from의 마지막 항목이
모듈인 경우임
"""

