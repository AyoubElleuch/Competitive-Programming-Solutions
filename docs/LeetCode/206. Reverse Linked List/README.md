# 206. Reverse Linked List

[Source code](../../../LeetCode/206.%20Reverse%20Linked%20List.cpp) | [All LeetCode explanations](../README.md)

The code reverses the list one link at a time. Prev is the head of the already reversed prefix, and current is the first node that has not yet been reversed.

Before changing current->next, it saves that pointer in next so the rest of the original list is still accessible. It then points current back to prev, advances prev to current, and continues from the saved next node. When current becomes null, prev is the head of the full reversed list.

For [1,2,3], the reversed prefix grows from [1] to [2,1] and finally [3,2,1]. The original first node becomes the tail because its next pointer was set to null during the first iteration.

For N nodes, time is O(N) and working space is O(1). No nodes are allocated or deleted. Empty input returns immediately, and a single-node list is handled by the same loop. The input is assumed acyclic.
