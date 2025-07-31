# LINEAR ALGEBRA PROJECT

## What is it?
A program written in C++, intended to solve stuff related to 
linear algebra, like matrices (primarily), complex numbers, matrices with
complex numbers etc. You can call it a poor man's MATLAB.
Just a fun little project, because I like algebra
and want to learn C++.

## MVP plan

- [x] `Matrix` class (obviously), with:
    - [x] Basic arithmetic operations:
        - [x] Sum & subtraction by matrix
        - [x] Multiplication & division by scalar/matrix
    - [x] Matrix-associated methods:
        - [x] Transposition: `transpose()`
        - [x] Determinant: `det()`
        - [x] Inverse matrix: `inverse()`
    - [x] Pre-determined matrices:
        - [x] Identity matrix: `identity(int order)`
        - [x] Diagonal matrix: `diagonal(vector<double> values)`

Rather humble, but is a subject to change, I guess.

## Future Plans
- [ ] BETTER CONSTRUCTOR/PARSER
- [ ] Calculate matrix eigenvalues and eigenvectors?
- [ ] `complex` class, with:
    - [ ] Basic arithmetics:
        - [ ] Sum, subtract, multiply, divide with either real (double)
        or complex values
    - [ ] Add complex matrices support, perhaps a virtual `Matrix` class with
    derived `RealsMatrix` and `ComplexMatrix`?
- [ ] `vector2`, `vector3` classes
- [ ] GUI/CLI?
