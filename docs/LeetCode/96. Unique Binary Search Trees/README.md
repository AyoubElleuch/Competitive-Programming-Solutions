# 96. Unique Binary Search Trees

[Source code](../../../LeetCode/96.%20Unique%20Binary%20Search%20Trees.cpp) | [All LeetCode explanations](../README.md)

The recursive function counts binary search tree structures using the number of keys. It tries each possible root i from 1 through n. That choice leaves i-1 smaller keys in the left subtree and n-i larger keys in the right subtree.

The two subtree choices are independent, so their counts are multiplied. Summing those products over all roots gives dp[n]. The base cases n=0 and n=1 both return one: an empty subtree is one valid choice when combining a larger tree.

For n=3, the three root choices contribute 1*2, 1*1, and 2*1, giving five structures. Actual key values do not need to be stored because their sorted order determines which side of a root they belong on.

Memoization computes each subtree size once, with a loop over its possible roots, giving O(N²) time. The table and recursion stack use O(N) space. Counts are Catalan numbers stored as int; n=19 fits a 32-bit signed int, while n=20 does not. The implementation assumes n is non-negative.
