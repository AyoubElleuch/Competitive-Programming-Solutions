# 142. Linked List Cycle II

[Source code](../../../LeetCode/142.%20Linked%20List%20Cycle%20II.cpp) | [All LeetCode explanations](../README.md)

The solution first detects whether the list contains a cycle. Slow advances one link while fast advances two. If fast reaches the end, the function returns null. If the pointers meet, they are inside a cycle.

It then resets slow to the head and moves both pointers one link per iteration. Their next meeting is the cycle entry. To see why, let a be the distance to the entry and b the distance from the entry to the first meeting. The first phase implies a+b is a multiple of the cycle length. Moving a steps from the meeting therefore reaches the entry, at the same time as the pointer starting at the head.

For nodes 3,2,0,-4 with the last node linked back to the node containing 2, the function returns that node's pointer. It identifies the node itself rather than searching for a repeated value.

For N distinct reachable nodes, time is O(N) and working space is O(1). Links are unchanged. Empty and ordinary single-node lists return null; a self-loop is detected by the pointer meeting.
