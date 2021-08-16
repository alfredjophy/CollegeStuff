#!/bin/python
#
#   Binary Search
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

element = int(input("Enter the number to search for : "))

lower = 0
upper = number_of_elements-1

while lower < upper :
    mid = (lower+upper)//2
    if numbers[mid] == element :
        print("The number found at position",mid+1)
        break
    elif element < numbers[mid] :
        upper=mid-1
    else : 
        lower=mid+1

if not (lower < upper) :
    print("Number not found.")
