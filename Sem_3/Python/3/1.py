#!/bin/python
#
#   Linear Search
#
number_of_elements = int(input("Enter the number of elements : ")) 

numbers = []

for i in range(number_of_elements) : 
    num=int(input("Enter the element"+str(i+1)+" : "))
    numbers.append(num)

print(numbers)

element = int(input("Enter the number to search for : "))

for i in range(number_of_elements) :
    if numbers[i] == element :
        print("Element found at position",i)


