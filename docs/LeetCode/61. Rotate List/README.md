# 61. Rotate List

[Source code](../../../LeetCode/61.%20Rotate%20List.cpp) | [All LeetCode explanations](../README.md)

The code first finds the list length and reduces k modulo that length. Rotating a list by its length returns the original order, so this removes unnecessary full cycles.

It then performs the remaining rotations individually. For each rotation, slow and fast walk to the last two nodes. The last node is connected to the old head, its predecessor is made the new tail, and head becomes the former last node.

For [1,2,3,4,5] with k=2, the first rotation gives [5,1,2,3,4], and the second gives [4,5,1,2,3]. Empty and single-node lists return immediately. A k divisible by the length leaves the links unchanged.

Let N be the length and R = k mod N. Finding the length costs O(N), and each of R rotations scans the list, giving O(N(1+R)) time and O(N²) worst-case time. Working space is O(1). The code relinks existing nodes and assumes k is non-negative.
