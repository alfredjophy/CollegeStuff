#!/bin/python
#
# Write a program to find the roots of a quadratic equation 
#
print("Alfred Jophy CS27          11/03/2021")

import math

print("Form of a quadratic equation : ax^2 + bx + c")

a=int(input("Enter the coefficient for x^2 : "))
b=int(input("Enter the coefficient for x : "))
c=int(input("Enter c : "))

print("\nThe Equation : "+str(a)+"x^2 + "+str(b)+"x+",c)

d= b**2 - 4*a*c
if d < 0 :
    print("No real roots")
elif d ==0 :
    root=-b/(2*a)
    print("Equal roots :",root)
else:
    root1=-b+math.sqrt(d)
    root2=-b-math.sqrt(d)
    root1/=2*a
    root2/=2*a
    print("Roots of the eqaution :",root1,root2)

