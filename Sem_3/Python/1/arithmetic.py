#!/bin/python

num1=int(input("Enter the first number: "))
num2=int(input("Enter the second number: "))

s=num1+num2
d=num1-num2
p=num1*num2

if num2 == 0:
    q="Undefined"
else :
    q=num1/num2

print(num1,"+",num2,"=",s)
print(num1,"-",num2,"=",d)
print(num1,"x",num2,"=",p)
print(num1,"/",num2,"=",q)
