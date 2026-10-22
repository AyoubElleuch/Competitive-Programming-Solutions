# 647. Palindromic Substrings

[Source code](../../../LeetCode/647.%20Palindromic%20Substrings.cpp) | [All LeetCode explanations](../README.md)

The code begins with s.size() palindromes because every individual character is one. It then expands around every odd and even centre to count longer palindromic substrings.

For an odd centre at i, the pointers start at i-1 and i+1. Every matching pair adds one palindrome before the pointers expand again. For an even centre, they start at i-1 and i, allowing length-two palindromes and their extensions. Each substring has a unique centre, so these expansions count each occurrence once.

For 'aaa', the initial count is three. The odd centre adds 'aaa', and the two even centres add the two occurrences of 'aa', giving six. Equal text at different positions is counted separately.

For N characters, time is O(N²) in the worst case, with O(1) working space for the expansion pointers and count. The by-value string parameter can add O(N) space for its copy. The total uses int and must fit that type; empty input returns zero.
