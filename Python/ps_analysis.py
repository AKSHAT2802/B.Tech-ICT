# -*- coding: utf-8 -*-
"""PS_analysis.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1d5WUkTyo4pXkjO8EyGbBNDLDtTv9gXCR
"""

import math
import matplotlib.pyplot as plot
Marks=[8,8,12,15,18,0,16,13,12,16,12,6,18,12,12,19,17,17,15,15,17,6,12,12,12,20,20,13,12,20,18,19,19,18,13,19,20,20,0,4,13,4,4,14,14,18,12,0,4,3,20,19,0,3]

l1=[0,3,4,6,8,12,13,14,15,16,17,18,19,20]
l2=[4,2,4,2,2,10,4,2,3,2,3,5,5,6]
# SIMPLE FREQUENCY
plot.bar(l1, l2, width = 0.3, color=['blue'])
plot.xlabel('Marks')
plot.ylabel('frequency of marks')
plot.title('Freq Graph')
plot.show()

import math
import matplotlib.pyplot as plot

Marks=[8,8,12,15,18,0,16,13,12,16,12,6,18,12,12,19,17,17,15,15,17,6,12,12,12,20,20,13,12,20,18,19,19,18,13,19,20,20,0,4,13,4,4,14,14,18,12,0,4,3,20,19,0,3]
a=0 # For 0-4
b=0 # For 4-8
c=0 # For 8-12
d=0 # For 12-16
e=0 # For 16-20
for i in Marks:
  if i>=0 and i<4:
    a=a+1
  elif i>=4 and i<8:
    b=b+1
  elif i>=8 and i<12:
    c=c+1
  elif i>=12 and i<16:
    d=d+1
  elif i>=16 and i<=20:
    e=e+1
ls=[a,b,c,d,e]

# BAR
interval = [0,4,8,12,16] 
value = ['0-4','4-8','8-12','12-16','16-20'] # labels for bar
plot.bar(interval, ls, tick_label = value, width = 2.0, color = ['yellow'])
plot.xlabel('Range of marks')
plot.ylabel('Frequency')
plot.title('Bar Graph')
plot.show()

# FREQUENCY
l1=[0,3,4,6,8,12,13,14,15,16,17,18,19,20]
l2=[4,2,4,2,2,10,4,2,3,2,3,5,5,6]
plot.plot(l1, l2, color='blue', linestyle='solid', linewidth = 2, marker='o', markerfacecolor='blue', markersize=7)# plotting the points
plot.xlabel('Marks')
plot.ylabel('Frequency of marks')
plot.title('Frequency Polygon')
plot.show()

# PIE
section = ['0-4','4-8','8-12','12-16','16-20'] #  labels
colors = ['r', 'b', 'g', 'y', 'g']
plot.pie(ls, labels = section, colors=colors,startangle=90, shadow = True, explode = (0, 0, 0, 0,0.1),radius = 1.2, autopct = '%1.2f%%') 
plot.legend() 
plot.show()

# OGIEVE
l1=[0,3,4,6,8,12,13,14,15,16,17,18,19,20]
l2=[4,2,4,2,2,10,4,2,3,2,3,5,5,6]
sum=0
for i in l2:
  sum=sum+i
print (sum)
l3=[0.074,0.111,0.185,0.222,0.259,0.444,0.518,0.5550,0.610,0.647,0.702,0.794,0.886,1]

plot.plot(l1, l3)
plot.xlabel('Marks')
plot.ylabel('Cumulative frequency')
plot.title('Ogieve plot')
plot.show()

# BOX
Marks=[8,8,12,15,18,0,16,13,12,16,12,6,18,12,12,19,17,17,15,15,17,6,12,12,12,20,20,13,12,20,18,19,19,18,13,19,20,20,0,4,13,4,4,14,14,18,12,0,4,3,20,19,0,3]
fig = plot.figure(figsize =(6, 4))
plot.boxplot(Marks) 
plot.show()

import math
import matplotlib.pyplot as plot
import stemgraphic
Marks=[8,8,12,15,18,0,16,13,12,16,12,6,18,12,12,19,17,17,15,15,17,6,12,12,12,20,20,13,12,20,18,19,19,18,13,19,20,20,0,4,13,4,4,14,14,18,12,0,4,3,20,19,0,3]
stemgraphic.stem_graphic(Marks, scale = 5)