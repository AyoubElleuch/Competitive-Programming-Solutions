# 287. Find the Duplicate Number

[Source code](../../../LeetCode/287.%20Find%20the%20Duplicate%20Number.cpp) | [All LeetCode explanations](../README.md)

The array is treated as a linked structure: from index i, the next index is nums[i]. With N+1 elements whose values lie in 1 through N, every jump is valid, and the sequence starting at index zero must eventually enter a cycle.

Slow takes one jump and fast takes two until they meet. Slow is then reset to zero, and both pointers take one jump at a time. Their next meeting is the cycle entry. Under the problem's single-duplicate assumption, that entry is the duplicated value: the initial path and the cycle both lead into it.

For [1,3,4,2,2], the index sequence is 0,1,3,2,4,2,... . Its cycle begins at 2, so the function returns 2. This uses the same meeting-and-reset argument as finding a cycle entry in a linked list.

Time is O(N) and space is O(1). The array is unchanged. Values outside 1 through N can cause invalid indexing or break the reasoning, and the method depends on the stated duplicate-number input conditions.
