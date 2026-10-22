# 230. Kth Smallest Element in a BST

[Source code](../../../LeetCode/230.%20Kth%20Smallest%20Element%20in%20a%20BST.cpp) | [All LeetCode explanations](../README.md)

The stack performs an iterative inorder traversal. The code follows left children while saving ancestors, then pops the next node, increments counter, and starts exploring that node's right subtree.

In a valid BST, inorder visits values in increasing order, so the kth popped node contains the answer. The function returns as soon as counter reaches k instead of collecting every value. Although the source comment calls this BFS, the stack and left-first traversal implement depth-first inorder traversal.

For a root 3 with left child 1, node 1's right child 2, and right child 4, the pop order begins 1,2,3. With k=2, the function returns 2 before visiting the remaining values.

For tree height H, time is O(H+k), bounded by O(N), and stack space is O(H). The implementation assumes a valid nonempty BST and 1 <= k <= N. If no kth node exists, traversal ends with current null and the final return dereferences it.
