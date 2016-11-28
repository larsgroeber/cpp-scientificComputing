#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
 Problem 2 (Recursive functions) 7 Pts
(a) Find a reduction formula for the following integral. (1)
(Hint: Integration by parts)

(b) Implement forward and backward recursion, setting the parameter a = 1.
(Hint: For the backward recursion you can assume the Integral to be ≈ 0
for n = 50.)

(c) By successively reinserting the reduction formula into itself, i.e.(2)
ﬁnd a series representation for the integral and write a program to im-
plement this series!

(d) Print the forward, backward recursion and the series representation for
a range of n for a < 1 and a > 1. Where do the single methods brake
down? What is the reason? How is the stability of the formulas related
to the parameter a?
 */