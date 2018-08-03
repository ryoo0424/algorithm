import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("C:/Users/fbwjd/Desktop//Titanic.csv", engine='python')
frame = pd.DataFrame(data)
df = frame.loc[:, ['Class', 'Survived']]

first_s = df[(df['Survived'] == "T") & (df['Class'] == "1st Class")]
second_s = df[(df['Survived'] == "T") & (df['Class'] == "2nd Class")]
third_s = df[(df['Survived'] == "T") & (df['Class'] == "3rd Class")]
victual_s = df[(df['Survived'] == "T") & (df['Class'] == "Victualling")]
engine_s = df[(df['Survived'] == "T") & (df['Class'] == "Engine")]
deck_s = df[(df['Survived'] == "T") & (df['Class'] == "Deck")]

labels = ['1st Class', '2nd Class', '3rd Class', 'Engine', 'Deck', 'Victualling']
ratio = [first_s['Class'].count(), second_s['Class'].count(), third_s['Class'].count(), engine_s['Class'].count(), victual_s['Class'].count(), deck_s['Class'].count()]
explode = [0.1, 0, 0, 0, 0, 0]

print(ratio)

plt.pie(ratio, labels=labels, explode=explode, autopct='%1.1f%%', shadow=True, startangle=90)
plt.show()
