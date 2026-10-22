# 104. Maximum Depth of Binary Tree

[Source code](../../../LeetCode/104.%20Maximum%20Depth%20of%20Binary%20Tree.cpp) | [All LeetCode explanations](../README.md)

The function measures depth with breadth-first search. It puts the root in a queue, then processes one complete level at a time.

At the start of each outer iteration, size records how many nodes belong to the current level. Processing exactly that many nodes removes them and appends their children. Newly appended children remain for the next iteration. Incrementing depth once per batch therefore counts levels rather than individual nodes.

For a root with two children and no grandchildren, the queue has one node in the first batch and two in the second, so the answer is two. An empty tree returns zero before anything is queued. A single-node tree returns one.

For N nodes, time is O(N), since each node is queued and removed once. Queue storage is O(W), where W is the maximum width, and O(N) in the worst case. The code uses no recursive calls and does not modify the tree.
