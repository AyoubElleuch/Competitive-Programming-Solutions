# Longest Increasing Subsequence

[Source code](../../../Algorithms/Longest%20Increasing%20Subsequence.cpp) | [All Algorithms explanations](../README.md)

The vector seq stores the smallest known ending value for an increasing subsequence of each length. seq[k] is a candidate tail for length k + 1, not necessarily an element of one shared subsequence.

The first input value initializes seq. For each later value, the program appends it if it is larger than the last tail. Otherwise lower_bound finds the first tail greater than or equal to that value, and the program replaces that tail. A smaller tail leaves more possibilities for extending a subsequence later, while preserving the length already achieved.

For (3, 1, 2, 2, 4), the tails are (3), then (1), then (1, 2). The second 2 replaces the existing 2, and 4 extends the vector to (1, 2, 4). The printed length is 3. Using lower_bound means equal values do not extend the subsequence: the sequence must be strictly increasing.

For N values, binary searches give O(N log N) time and the tails vector uses O(N) space. The input array is allocated at K = 1000001 entries, so total storage is O(K + N). The implementation expects 1 <= N <= 1000000. For N = 0 it still inserts v[1] and incorrectly prints 1. Only the length is returned; the tails vector alone does not reconstruct an input subsequence.
