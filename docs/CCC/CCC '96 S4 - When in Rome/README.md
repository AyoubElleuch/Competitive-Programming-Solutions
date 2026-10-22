# CCC '96 S4 - When in Rome

[Source code](../../../CCC/CCC%20'96%20S4%20-%20When%20in%20Rome.cpp) | [All CCC explanations](../README.md)

The program separates each expression at the plus sign, leaving out the trailing equals sign. It converts both Roman numerals to integers, adds them, and appends the result to the original expression.

`romanToInt` scans from left to right. The helper `valid` recognizes the six subtractive pairs IV, IX, XL, XC, CD, and CM. For one of those pairs it adds the larger value minus the smaller and skips both characters. Otherwise, it adds the current symbol's value.

To convert the sum back, `intToRomans` tries values in descending order, including subtractive pairs. It repeatedly appends the largest symbol or pair that fits the remaining amount. For `IX+VI=`, the operands become 9 and 6, and 15 becomes `XV`, producing `IX+VI=XV`.

A sum greater than 1000 prints `CONCORDIA CUM VERITATE`; exactly 1000 is printed as `M`. For total input length L and output length S, conversion takes expected O(L + S) time with the fixed symbol lookup table, and O(L + S) space for strings. The code assumes valid Roman numerals and expressions with a plus sign and trailing equals sign. It does not validate arbitrary numeral syntax.
