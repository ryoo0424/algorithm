text = ["dbpia.txt", "ndsl.txt", "papersearch.txt", "riss.txt"]

with open("merge.txt", "a", encoding="utf8") as m:
    for head in text:
        with open(head, "r", encoding="utf8") as f:
            while True:
                line = f.readline()
                if not line:
                    break
                if ("텍스트" or "마이닝") in line:
                    m.write(line)
