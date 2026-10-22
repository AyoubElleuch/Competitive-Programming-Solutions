# 94. Binary Tree Inorder Traversal

[Source code](../../../LeetCode/94.%20Binary%20Tree%20Inorder%20Traversal.cpp) | [All LeetCode explanations](../README.md)

An explicit stack replaces recursive inorder traversal. The code repeatedly pushes the current node and follows left children until it reaches null.

The stack's top is then the next node whose left subtree has been fully processed. The code pops it, appends its value, and begins exploring its right subtree. This produces left-subtree values, then the node, then right-subtree values. Every node is pushed and popped once.

For a root 2 with children 1 and 3, the stack first saves 2 and 1. Popping 1, then 2, and finally processing 3 gives [1,2,3]. Inorder traversal applies to any binary tree; the resulting values are sorted when the tree is a valid binary search tree.

For N nodes and height H, time is O(N), stack space is O(H), and the returned vector uses O(N) space. A skewed tree can make H=N. Empty input returns an empty vector, and the tree is unchanged.
