## ST THOMAS COLLEGE , THRISSUR
## Department of Computer Science
## BSc Computer Science (2020-2023) - Semester III

## Assignment 1
### Compressing a Sparse Matrix


#### Question 1
Accept a matrix from the user and store the coordinates of non-zero elements and the respective non-zero value in a 2D array as a triplet {x,y,value}. 
Also , store the number of rows, columns and number of non-zero elements(NNZ) as the first entry in the 2D array {row_count,column_count,NNZ}.


* Accept a matrix from the user

* Compress the matrix into 2D array stroing triplets of form {x,y,value}
  The first entry must be {row_count,column_count,NNZ}

* Display the 2D array

### Input Matrix 
```
        1 0 0 0
        0 2 0 0
        1 0 0 0
        0 7 0 1
```

### Output 2D array
```
        4 4 5           // rows columns NNZ
        0 0 1           // X Y Value
        1 1 2           
        2 0 1                
        3 1 7           
        3 3 1           

```

\newpage
#### Question 2 
Accept a matrix from the user and check if it is a sparse matrix.
If it is a sparse matrix , compress the matrix into a 2D array or linked list

*Condition for being a sparse matrix*        
```
number of non zero elements < (total number of elements in the matrix)/2
```


* Accept matrix from user

* Check if the matrix is sparse and display the result.

* if sparse , compress the matrix and display the compressed form

### Input Matrix
```
        
        0 0 0 5
        0 2 0 0
        0 0 1 0
        7 0 0 0
        
```

### Output
```
The matrix is sparse.

Compressed representation of the sparse matrix:

        4 4 4
        0 3 5
        1 1 2
        2 2 1
        3 0 7

```

### Input Matrix
```
        1 1 0
        0 1 1
        1 0 1
```

### Output Matrix
```
The matrix is not sparse
```

