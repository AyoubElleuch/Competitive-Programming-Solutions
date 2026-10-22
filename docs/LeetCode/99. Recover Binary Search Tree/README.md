# 99. Recover Binary Search Tree

[Source code](../../../LeetCode/99.%20Recover%20Binary%20Search%20Tree.cpp) | [All LeetCode explanations](../README.md)

A valid binary search tree has an increasing inorder sequence. The solution recursively collects pointers to all nodes in that order, then scans their values for descending adjacent pairs.

At the first inversion, it records the larger node as first. At every inversion, it updates second to the smaller node. If the swapped values were adjacent in inorder order, there is one inversion. If they were separated, the first inversion identifies the earlier misplaced large value, and the last inversion identifies the later misplaced small value.

For inorder values [1,4,3,2,5], the inversions are 4>3 and 3>2. The recorded nodes contain 4 and 2; swapping their values restores [1,2,3,4,5]. Node links and the tree structure remain unchanged.

For N nodes, time is O(N), the pointer vector uses O(N) space, and recursive traversal uses O(H) stack space for height H. The method assumes the problem's condition that exactly two values in an otherwise valid BST were swapped. It does not repair arbitrary ordering errors.
