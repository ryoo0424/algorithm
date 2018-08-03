(ggplot(mpg) +
 aes(x='manufacturer', color="manufacturer") +
 geom_bar(size=20, color=mpg) +
 coord_flip() +
 ggtitle('Number of Cars by Make')
 )

geom_density()
geom_smooth()

pythonplot.com
spurious correlation