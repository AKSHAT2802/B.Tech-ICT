# -*- coding: utf-8 -*-
"""My Fruit Shop.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1Qu9SETOmOwsrVzh2Lpw_hdAFBtMFSmfl
"""

from google.colab import output
amt={}
st={}
profit=0
while(1):
  print("ENTER 1 FOR PURCHASE")
  print("ENTER 2 FOR SELLING")
  print("ENTER 3 FOR CHECKING STOCK")
  print("ENTER 4 FOR A GLANCE OF PROFIT")
  print("ENTER 5 FOR AVALIABLE FRUIT NAME")
  print("ENTER 6 TO EXIT")
  a=int(input("ENTER YOUR CHOICE    :  "))
  if a==1:
    output.clear()
    b=input("ENTER FRUIT NAME    : ")
    c=input("ENTER PRICE PER FRUIT    : ")
    d=input("ENTER KILOGRAMS    :  ")
    amt[b]=c
    st[b]=d
    print("FRUIT ADDED SUCCESSFULLY")
    print()
  if a==2:
    output.clear()
    e=input("ENTER NAME OF FRUIT   : ")
    if st.get(e)==None or st.get(e)==0:
      print("SORRY FRUIT NOT AVAILABLE")
    else:
      print("PRICE OF THE",e,"IS",(int(amt[e])+int(amt[e])*0.15))
      kg=int(input('Enter quantity in kg : '))
      if kg>int(st[e]):
        print("ENTERED KILOGRAM IS NOT AVAILABLE WITH US")
        if int(st[e])==0:
          continue
        else :
          print('We have',st[e],'kg availble only')
          choice1=input('1->for buying... \n2-> Not Buying..')
          if choice1=='1':
            kg=int(input('Enter quantity in kg : '))
            if kg>int(st[e]):
              print("SORRY STOCK NOT AVAILABLE")
              print("PLEASE REPEAT TO TRY AGAIN")
              continue
            old=int(st[e])
            New=old-kg
            st[e]=New
            print('You have to pay',(kg*(int(amt[e])+int(amt[e])*0.15)))
            profit=profit+int(amt[e])*0.15
            print('Thanks for shopping with us..')
          elif choice1=='2':
            continue
          else :
            print('You have entered invalid choice..')
            continue
      else :
        print('You have to pay',(kg*(int(amt[e])+int(amt[e])*0.15)))
        old=int(st[e])
        New=old-kg
        st[e]=New
        profit=profit+int(amt[e])*0.15*kg
        print('Thanks for shopping with us..')      
  elif a==3:
    output.clear()
    print('Let us have a glance on stock ..')
    print(st)
  elif a==4: 
    output.clear()
    print('Total profit for today is : ',profit)
  elif a==5:
    output.clear()
    print('Available fruits are :')
    print(st.keys())
  elif a==6:
    break
  else:
    print("ENTER A VALID CHOICE")
    continue