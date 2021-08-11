#!/bin/python
#
# Write a program to check if a given number is a prime
#
print("Alfred Jophy CS27          11/03/2021")

import math

num=int(input("Enter the number : "))

f=True
for i in range(2,math.isqrt(num)):
    if num % i ==0 :
        f=False
        break

if f : 
    print("The number is a prime.")
else :
    print("The number is not a prime.")

