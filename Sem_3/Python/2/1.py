#!/bin/python
#
# Write a program to find the largest among three numbers
#
print("Alfred Jophy CS27          11/03/2021")

a=int(input("Enter first number : "))
b=int(input("Enter second number : "))
c=int(input("Enter third number : "))

if a >= b and a >= c :
    largest = a
elif b >= a and b >= c :
    largest = b
else : 
    largest = c

print("Largest number is",largest)

