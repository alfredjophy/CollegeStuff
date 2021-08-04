---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---

# Python Fundamentals

![](./1.png)

## 1. Accept name and birthday from user and display as separate line

![](./2.png)

## 2. Categories the below into runtime , syntax or logical errors
1. `25/0`
    

    Runtime Error

2. `Print 'Hello'`
    
    
    Syntax Error

3. 

    ```python
    num1=25
    num2=0
    C=num1/num2
    ```
    
    Runtime Error

    ![](./3.png)

## 3. Find the output of the below

1. `bool(int('0'))`

2. `bool(str(0))`

3. `bool(float(0.0))`

4. `bool(str(0.0))`

    ![](./4.png)

## 4. Find the output
```python
str1='''Hell
o
'''
str2='''Hell\
o
'''
print(len(str1) > len(str2))
```
    
*  ![](./4_5.png)

### 5. Find the output of the below
1. `type(6+3)`
2. `type(6-3)`
3. `type(6*3)`
4. `type(6/3)`
5. `type(6//3)`
6. `type(6%3)`

    ![](./5.png)

### 6. Give output of the following when `num1=4,num2=3,num3=2`

1. 
    
    ```python
    num1+=num2+num3
    print (num1)
    ```
2. 
    
    ```python
    num1=num1**(num2+num3)
    print(num1)
    ```
3. 
    
    ```python
    num1**=num2+num3
    print(num1)
    ```
4. 
    
    ```python
    num1='5'+'5'
    print(num1)
    ```
5. 
    
    ```python
    print (4.00/(2.0+2.0))
    ```
6. 
    
    ```python
    num1=2+9*((3*12)-8)/10
    print(num1)
    ```
7. 
   
   ```python
   num1=24//4//2
   print(num1)
   ```
8. 
    
    ```python
    num1=float(10)
    print(num1)
    ```
9. 
    
    ```python
    num1=int('3.14')
    print(num1)
    ```
10. `print('Bye'== 'BYE')`

    ![](./6_1.png)
    ![](./6_2.png)

\newpage

## 7. Write a program to enter two integers and perform all arithmetic operations on them (+,-,*./)

### Source Code
```python
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
```

### Output

1. ![](./l1.png)

2. ![](./l2.png)
