from bs4 import BeautifulSoup
from urllib.request import urlopen

articles = 1 #처음 while 루프를 돌기 위한 값
i = 0 #크롤링을 위한 웹페이지 start index 값
lists = [] #크롤링 한 논문 제목들을 저장할 리스트

while articles:
    url = "http://www.riss.kr/search/Search.do?detailSearch=false&viewYn=OP&query=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D&queryText=&strQuery=%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%A7%88%EC%9D%B4%EB%8B%9D&iStartCount="\
          + str(i) +\
          "&iGroupView=5&icate=bib_t&colName=bib_t&exQuery=&pageScale=100&strSort=RANK&order=%2FDESC&onHanja=false&keywordOption=0&searchGubun=true&p_year1=&p_year2=&dorg_storage=&mat_type=&mat_subtype=&fulltext_kind=&t_gubun=&learning_type=&language_code=&ccl_code=&language=&inside_outside=&fric_yn=&image_yn=&regnm=&gubun=&kdc=&resultSearch=false&listFlag=&h_groupByField=&orderBy="
    html = urlopen(url)
    source = html.read()
    html.close()

    soup = BeautifulSoup(source, "html5lib")
    table = soup.find(class_="UnifiedSearch")
    articles = table.find_all(class_="txt")

    for article in articles:
        title = article.get_text()
        #print(title)
        #link = article.a.get("href")
        #url = "http://www.riss.kr/" + link
        #print(url)
        lists.append(title)
    i += 100

with open("riss.txt", "w", encoding="utf8") as f:
    for head in lists:
        f.write(head+"\n")

