from bs4 import BeautifulSoup
import urllib.request


#자동 크롤링 차단을 우회하기
class NewOpener(urllib.request.FancyURLopener):
    version = "Mozilla/5.0"


articles = 1 #처음 while 루프를 돌기 위한 값
i = 0 #크롤링을 위한 웹페이지 start index 값
lists = [] #크롤링 한 논문 제목들을 저장할 리스트
opener = NewOpener()

while True:
    url = "https://scholar.google.co.kr/scholar?start="\
          + str(i) +\
          "&q=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D&hl=ko&as_sdt=0,5"
    html = opener.open(url)
    source = html.read()
    html.close()

    soup = BeautifulSoup(source, "html5lib")
    table = soup.find(id="gs_res_ccl_mid")
    articles = table.find_all(class_="gs_ri")

    if not articles:
        break

    for article in articles:
        title = article.get_text()
        print(title)
        #link = article.a.get("href")
        #url = "http://www.riss.kr/" + link
        #print(url)
        lists.append(title)
    i += 10

print(lists)

with open("scholar_google.txt", "w", encoding="utf8") as f:
    for head in lists:
        f.write(head + "\n")
