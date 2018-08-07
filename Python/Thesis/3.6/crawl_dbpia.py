from bs4 import BeautifulSoup
from urllib.request import urlopen


articles = 1 #처음 while 루프를 돌기 위한 값
i = 1 #크롤링을 위한 웹페이지 start index 값
lists_tmp = [] #크롤링 한 논문 제목들을 임시 저장할 리스트
lists = [] #포매팅하여 실제로 저장할 리스트

while articles:
    url = "http://www.dbpia.co.kr/SearchResult/Search?q=%28%5B%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D%C2%A7coldb%C2%A72%C2%A751%C2%A73%5D%29&searchWord=%EC%A0%84%EC%B2%B4%3D%5E%24%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D%5E*&Collection=0&nSort=1&nSorttype=desc&Page="\
            + str(i) +\
          "&nPagesize=200&searchAll=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D&Multimedia=0&specificParam=0&isFullText=0"
    html = urlopen(url)
    source = html.read()
    html.close()

    soup = BeautifulSoup(source, "html5lib")
    table = soup.find(class_="subSearchResultList")
    articles = table.find_all(class_="titleWarp")

    for article in articles:
        title = article.get_text()
        print(title)
        #link = article.a.get("href")
        #url = "http://www.riss.kr/" + link
        #print(url)
        lists_tmp.append(title)
    i += 1

for tmp in lists_tmp:
    lists.append(tmp.split("\xa0")[0])

print(lists)

with open("dbpia.txt", 'w', encoding="utf8") as f:
    for head in lists:
        f.write(head+"\n")
