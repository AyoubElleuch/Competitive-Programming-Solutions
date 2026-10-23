# Longest Common Subsequence

[Source code](../../../Algorithms/Longest%20Common%20Subsequence.cpp) | [All Algorithms explanations](../README.md)

The program reads two integer sequences and returns the length of their longest common subsequence. Elements may be skipped, but their order must be preserved.

solve(i, j) gives the answer for the suffixes starting at i and j. If either sequence has ended, the answer is zero. When the current values match, the function takes that match and adds one to solve(i + 1, j + 1). Otherwise it tries skipping the current element of either sequence and keeps the larger answer.

Matching equal leading elements can be part of an optimal subsequence. For unequal leading elements, a common subsequence must omit at least one of them, so the two recursive choices cover the possibilities. For (1, 2, 3) and (2, 1, 3), the answer is 2; either (1, 3) or (2, 3) is a common subsequence.

The table starts at -1. A reference ret aliases dp[i][j], and if(~ret) returns a cached entry: bitwise NOT is zero for -1 and nonzero for computed lengths, including zero. This allows zero-length answers to be cached correctly.

For lengths N and M, at most NM states are computed, each with O(1) work. Time is O(NM + K²), including initialization of the fixed K = 1001 table. Storage is O(K² + N + M), and the recursive stack can be O(N + M) deep. Both lengths should be at most 1000. The program returns a length and does not reconstruct a subsequence.
