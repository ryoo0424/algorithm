import pandas as pd
import matplotlib.pyplot as plt
from ggplot import *

data = pd.read_csv("C:/Users/fbwjd/Desktop/team/8_CarsRegistered_PedestrianFatalities.csv", engine='python')
data.plot(kind="scatter", title="Cars Registered and Pedestrian Fatalities", x="CarsRegistered", y="PedestrianFatalities", alpha=0.4)
plt.show()

(ggplot(aes(x="CarsRegistered", y="PedestrianFatalities"), data=data) +
    geom_point(color='blue') +
    stat_smooth(span=.15, color='black', se=True) +
    ggtitle("Correlation between registered cars and pedestrian fatalities"))



