import pandas as pd
import statsmodels.api as sm
import statsmodels.formula.api as smf

t = pd.read_csv("C:/Users/fbwjd/Desktop/2018_ISS/Data Science and Management/titanic-train.csv", engine='python')

t.columns

formula = 's ~ Age * sex + Fare' # s: 0,1, ~: proportional, *: add, +: and

mod1 = smf.glm(formula=formula, data=t, family=sm.families.Binomial())

mod1.summary()

mod1.fitted = mod1.fit()

mod1.fitted.summary()
mod1.fitted.summary2()

#linear model in python
#https://www.statsmodels.org/stable/index.html


