# 5. Longest Palindromic Substring

[Source code](../../../LeetCode/5.%20Longest%20Palindromic%20Substring.cpp) | [All LeetCode explanations](../README.md)

Every palindrome has a centre: either one character or a gap between two characters. The code tries both possibilities at each position and expands outward while the characters match.

For an odd-length palindrome, the pointers begin at i-1 and i+1, with s[i] already in the middle. For an even-length palindrome, they begin at i-1 and i. After expansion stops, the matching substring starts at j+1 and has length k-j-1. The code saves its start and length if it is longer than the previous answer.

For 'cbbd', expansion around the gap between the two b characters finds 'bb'. For 'babad', an odd centre finds a length-three answer. Equal-length candidates do not replace the existing answer because the comparison uses a strict greater-than test.

For N characters, time is O(N²) in the worst case, such as a string of repeated letters. Searching uses O(1) working space. The final substring and the by-value input parameter use O(N) space. Empty input returns an empty string.
