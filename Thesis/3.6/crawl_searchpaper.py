from bs4 import BeautifulSoup
import urllib.request


#자동 크롤링 차단을 우회하기
class NewOpener(urllib.request.FancyURLopener):
    version = "Mozilla/5.0"


articles = 1 #처음 while 루프를 돌기 위한 값
i = 1 #크롤링을 위한 웹페이지 start index 값
lists = [] #크롤링 한 논문 제목들을 저장할 리스트
opener = NewOpener()

while True:
    url = "http://papersearch.net/search/sch-result.asp?page="\
          + str(i) +\
          "&sel_searchfield=ALL&query=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D"
    html = opener.open(url)
    source = html.read()
    html.close()

    soup = BeautifulSoup(source, "html5lib")
    table = soup.find(class_="sch-result-lists")
    articles = table.find_all("h3")

    if not articles:
        break

    for article in articles:
        title = article.get_text()
        lists.append(title)
    i += 1

with open("papersearch.txt", "w", encoding="utf8") as f:
    for head in lists:
        f.write(head + "\n")
