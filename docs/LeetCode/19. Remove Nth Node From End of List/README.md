# 19. Remove Nth Node From End of List

[Source code](../../../LeetCode/19.%20Remove%20Nth%20Node%20From%20End%20of%20List.cpp) | [All LeetCode explanations](../README.md)

Two pointers start at the head. The code advances p2 by n-1 nodes, leaving the pointers n-1 links apart. They then advance together until p2 reaches the last node.

At that point, p1 is the nth node from the end. The variable prev records its predecessor. If prev exists, its next pointer bypasses p1; otherwise, the removed node was the head and head is advanced. The code deletes the removed node and returns the updated head.

For [1,2,3,4,5] with n=2, p2 starts one link ahead. When it reaches 5, p1 is at 4 and prev is at 3, so the result is [1,2,3,5]. With n equal to the list length, p1 remains at the head.

For N nodes, time is O(N) and working space is O(1). Links are modified in place. The implementation assumes a nonempty list and 1 <= n <= N; invalid values can dereference null pointers. Deleting p1 assumes the node can be released with delete.
