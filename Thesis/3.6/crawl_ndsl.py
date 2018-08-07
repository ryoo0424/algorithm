from bs4 import BeautifulSoup
from urllib.request import urlopen

articles = 1 #처음 while 루프를 돌기 위한 값
i = 1 #크롤링을 위한 웹페이지 start index 값
lists = [] #크롤링 한 논문 제목들을 저장할 리스트

while True:
    url = "http://www.ndsl.kr/ndsl/search/list/article/articleSearchResultList.do?page="\
          + str(i) +\
          "&query=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D&prefixQuery=&collectionQuery=&showQuery=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D&resultCount=100&sortName=RANK&sortOrder=DESC&colType=scholar&colTypeByUser=&filterValue="
    html = urlopen(url)
    source = html.read()
    html.close()

    soup = BeautifulSoup(source, "html5lib")
    table = soup.find(class_="mid_section")
    articles = table.find_all(class_="title")

    if not table:
        break

    for article in articles:
        title = article.get_text()
        print(title)
        #link = article.a.get("href")
        #url = "http://www.riss.kr/" + link
        #print(url)
        lists.append(title)
    i += 1


