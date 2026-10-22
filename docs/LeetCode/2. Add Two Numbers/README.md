# 2. Add Two Numbers

[Source code](../../../LeetCode/2.%20Add%20Two%20Numbers.cpp) | [All LeetCode explanations](../README.md)

The lists store digits in reverse order, so the head contains the units digit. The code walks both lists together and adds their current digits plus the carry from the previous position. A missing digit contributes zero.

For each sum, integer division by 10 gives the next carry and the remainder gives the output digit. A new node is appended to the result. The loop continues while either list has digits or a carry remains, so an addition such as 99 + 1 produces the extra hundreds digit.

For lists [2,4,3] and [5,6,4], the digit sums produce [7,0,8], representing 342 + 465 = 807. Processing each position separately avoids converting the full numbers to a fixed-width integer.

For lengths M and N, time is O(max(M,N)). The result uses O(max(M,N)) newly allocated nodes; working storage besides the output is O(1). Input nodes are unchanged. The extra check for a digit above 9 is redundant after taking the remainder. Digits are assumed to be between 0 and 9.
