import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv("C:/Users/fbwjd/Desktop/Titanic.csv", engine='python')
y_pos = np.arange(len(data))
frame = pd.DataFrame(data)
print(frame)

# 1. Show a bar plot containing the number of passengers riding in each class
first = frame[frame['Class'] == "1st Class"]
print(first['Class'].count())
# 2. Show a histogram containing the number of passengers riding bt age.
#    Use a sensible value to bin the ages(binwidth)

# 3. Show a scatter plot of fare paid vs. age. You should log-transform the
#    y axis (use an axis transformation - do not transform the input directly)

# 4. Show survival probability (NOT counts) by age. Add a smoothed LOESS line
#    through it. (Hint: "pip install scikit-misc" may be necessary)
