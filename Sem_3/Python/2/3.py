#!/bin/python
#
# Write a program to check if a given string is a palindrome
#
print("Alfred Jophy CS27          11/03/2021")

string=input("Enter the string :")

strlen=len(string)

f=True

for i in range(0,strlen//2) :
    if string[i] != string[strlen-i-1] : 
        f=False
        break
if f :
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

    
