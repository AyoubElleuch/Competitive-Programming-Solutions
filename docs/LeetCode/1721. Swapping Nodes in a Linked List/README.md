# 1721. Swapping Nodes in a Linked List

[Source code](../../../LeetCode/1721.%20Swapping%20Nodes%20in%20a%20Linked%20List.cpp) | [All LeetCode explanations](../README.md)

The code locates the kth node from the beginning by advancing fast k-1 links from the head. It saves that node in kth_beg.

Slow then starts at the head while fast continues toward the tail. Moving both together preserves a gap of k-1 links. When fast reaches the final node, slow is the kth node from the end. The code exchanges those two nodes' val fields and returns the same head.

For [1,2,3,4,5] with k=2, the saved beginning node contains 2 and the ending node contains 4. Swapping their values gives [1,4,3,2,5]. If both positions refer to the middle node, swapping its value with itself leaves the list unchanged.

For N nodes, time is O(N) and working space is O(1). The links and node identities stay in place; the values are exchanged. The implementation assumes a nonempty acyclic list and 1 <= k <= N. An out-of-range k can dereference a null pointer.
