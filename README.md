# Euler
Project Euler in C++

The solutions in \_old I did when I was 17. The rest is more recent.

## 068: 5-gon ring
I used recursion with greedy pruning to fill out the nodes of the ring, creating only those that could be the solution. I then created an array of pointers to positions in the nodes, and used than to generate and compare the best answer.

## 069: greatest n/phi(n) for n < 1,000,000
I used bit arithmetic to implement the binary greatest common divisor algorithm, and used the multiplicative property of Euler's totient function to optimize it.

## 070: least n/phi(n) where n < 10,000,000 and n is a permutation of phi(n)
I reused most of the previous problem's solution, except I had to flip the tests, and write a function to compare the digits of two integers, returning false if one was ever not found.

## 071: reduced fraction n/d left of 3/7 where d < 1,000,000
I started with a denominator of 1,000,000 and worked up, multiplying the denominator by 3/7 to get the numerator, then comparing that to the previous closest.
