#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
 Problem 2 (Function pointer and header ﬁles) 6 Pts

 (a) For many purposes, such as integration methods, one has functions that
take a function as an argument. Write a function named eval that
evaluates a given function f at N points on the interval [a,b], where
f, N, a, b are given as arguments. More speciﬁc, pass f as a function
pointer. Test your code with any polynomial or trigonometric function
and plot it in gnuplot. (4 Pts)

 (b) For more complex project and especially when developing code in a
group, it can be useful to create a multi-ﬁle structure. Then there is
exactly one executable ﬁle containing the main function and all func-
tions, classes, structs etc. are loaded from external C++ ﬁles and header
ﬁles. E. g. a function is deﬁned in a separate C++ ﬁle (e. g. test.cpp)
and only the function body, i. e. with name, argument types, return type,
is deﬁned in a header ﬁle of same name (test.h). The function in the
external ﬁle can be loaded by including the corresponding header ﬁle
(#include "test.h"). Re-write the code from (a) into such a multi-ﬁle
project by creating a external C++ ﬁle and a corresponding header ﬁle
for the function eval. (2 Pts)
 */