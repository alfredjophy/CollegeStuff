#!/bin/python
#
# Write a program to print fibonacci series
#
print("Alfred Jophy CS27          11/03/2021")

lenght=int(input("Enter the lenght of the sequence :"))

tn_2=0
tn_1=1

print(tn_2)
print(tn_1)

for i in range(2,lenght):
    tn=tn_1+tn_2
    tn_2=tn_1
    tn_1=tn
    print(tn)
