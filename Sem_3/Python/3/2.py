#!/bin/python
#
#   Bubble Sort
#

number_of_elements = int(input("Enter the number of elements : ")) 

numbers = []

for i in range(number_of_elements) : 
    num=int(input("Enter the element"+str(i+1)+" : "))
    numbers.append(num)

print("\nThe List\n")
print(numbers)

for i in range(number_of_elements) : 
    for j in range(number_of_elements-i-1) :
        if numbers[j] > numbers[j+1] :
            numbers[j],numbers[j+1] = numbers[j+1],numbers[j]


print("The Sorted List")
print(numbers)
