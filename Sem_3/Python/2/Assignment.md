---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

# Python 

## 1.

### Source Code
```python
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

```

### Output
*
    ![](./1.png)

## 2.

### Source Code
```python
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

```

### Output
1.
    ![](./2_1.png)
2.
    ![](./2_2.png)
3. 
    ![](./2_3.png)

## 3.

### Source Code
```python
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

    
```

### Output
1.
    ![](./3_1.png)
2.
    ![](./3_2.png)

## 4.

### Source Code
```python
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

```

### Output
1.
    ![](./4_1.png)
2.
    ![](./4_2.png)

## 5.

### Source Code
```python
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
```

### Output
1. 
    ![](./5.png)
