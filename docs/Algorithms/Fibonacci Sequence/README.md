# Fibonacci Sequence

[Source code](../../../Algorithms/Fibonacci%20Sequence.cpp) | [All Algorithms explanations](../README.md)

The program computes F(n) modulo 1000000007, with F(0) = 0 and F(1) = 1. It uses powers of the two-by-two matrix Q = ((1, 1), (1, 0)). For k >= 1, the upper-left entry of Q^k is F(k + 1).

Both A and v initially contain Q. A is the matrix being squared; v is the accumulated result. matrix_power(n - 2) processes the exponent in binary. For each set bit it multiplies v by A, then halves the exponent and squares A. Because v starts at Q rather than the identity, the final result is Q^(n - 1). Its upper-left entry is F(n).

For n = 6, the exponent is 4. Repeated squaring produces Q^4, which is multiplied into the initial Q to give Q^5. The upper-left entry is 8, so the output is 8. Inputs 0 and 1 return directly; n = 2 uses exponent zero and returns the initial upper-left value 1.

There are O(log n) iterations, each doing a fixed amount of matrix arithmetic, with O(1) extra space. Each multiplication reduces entries modulo 1000000007. With the current modulus, the sum of two products fits in unsigned long long.

The input is read as unsigned long long and is intended to be nonnegative. A and v are mutable globals and are not reset inside matrix_power, so the helper is intended for the program's single call. The result is a residue modulo the stated modulus, not the full Fibonacci number.
