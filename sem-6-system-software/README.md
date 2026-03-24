# System Software Laboratory

## Description

Exercises to be prepared with minimum three files (Where ever necessary):
1. Header file. <br>
2. Implementation file. <br>
3. Application file where main function will be present. <br>
The idea behind using three files is to differentiate between the developer and user sides. In the developer side, all the three files could be made visible. For the user side only header file and application files could be made visible, which means that the object code of the implementation file could be given to the user along with the interface given in the header file, hiding the source file, if required. Avoid I/O operations (printf scanf) and use *data input file* where ever it is possible

## Programs List

### 1a

Write a LEX program to recognize valid *arithmetic expression.* Identifiers in the expression could be only integers and operators could be + and *. Count the identifiers & operators present and print them separately.

### 1b

Write YACC program to evaluate *arithmetic expression* involving operators: and /

### 2

Develop, Implement and Execute a program using YACC tool to recognize all strings ending with `b` preceded by `n` `a`’s using the grammar `a^n b` (note: input `n` value)

### 3

Design, develop and implement YACC/C program to construct `Predictive` / `LL(1) Parsing Table` for the grammar rules: `A → aBa` , `B → bB | ε` . Use this table to parse the sentence: `abba$`

### 4

Design, develop and implement YACC/C program to demonstrate Shift Reduce Parsing technique for the grammar rules: `E → E+T | T`, `T → T*F | F`, `F → (E) | id` and parse the sentence: `id + id * id`.

### 5

Design, develop and implement a C/Java program to generate the machine code using Triples for the statement `A = -B * (C +D)` whose intermediate code in three-address form:
`T1 = -B` <br>
`T2 = C + D` <br>
`T3 = T1 + T2` <br>
`A = T3` <br>

### 6a

Write a LEX program to eliminate *comment lines* in a C program and copy the resulting program into a separate file.

### 6b

Write YACC program to recognize valid *identifier*, *operators* and *keywords* in the given text (C program) file.

### 7

Design, develop and implement a C/C++/Java program to simulate the working of Shortest remaining time and Round Robin (RR) scheduling algorithms. Experiment with different quantum sizes for RR algorithm.

### 8

Design, develop and implement a C/C++/Java program to implement Banker’s algorithm. Assume suitable input required to demonstrate the results

### 9

Design, develop and implement a C/C++/Java program to implement page replacement algorithms LRU and FIFO. Assume suitable input required to demonstrate the results.

