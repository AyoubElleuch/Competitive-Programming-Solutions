# 9. Palindrome Number

[Source code](../../../LeetCode/9.%20Palindrome%20Number.cpp) | [All LeetCode explanations](../README.md)

The code rejects negative integers, then rebuilds a non-negative number with its digits reversed. Taking the remainder modulo 10 extracts the last digit; dividing by 10 removes it. Each extracted digit is appended to the reversed number by multiplying the previous result by 10.

Before that multiplication, the condition reversed_x > (INT_MAX - digit) / 10 checks whether the next value would overflow an int. If it would, the function returns false. A positive int whose reversal exceeds INT_MAX cannot equal that reversed value, so this rejection is safe.

For 121, the reversed values become 1, 12, and 121, which matches the input. For 10, the reversal is 1 and the comparison fails. Zero skips the loop and compares equal to its initial reversed value of zero.

For D decimal digits, time is O(D) and space is O(1). For a fixed-width int, D is bounded. The solution uses arithmetic rather than converting the number to a string.
