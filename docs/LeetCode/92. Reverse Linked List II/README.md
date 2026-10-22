# 92. Reverse Linked List II

[Source code](../../../LeetCode/92.%20Reverse%20Linked%20List%20II.cpp) | [All LeetCode explanations](../README.md)

The code reverses a segment by swapping its endpoint nodes, then recursively reversing the smaller segment between them. Each call searches from the head for the predecessors of the left and right endpoints.

It saves the endpoints' neighbouring nodes, reconnects the node before the segment to the old right endpoint, and reconnects the old left endpoint to the suffix after the segment. For non-adjacent endpoints, it also reconnects the unchanged interior between them, then calls reverseBetween with left+1 and right-1. Adjacent endpoints have a separate branch because their links overlap.

For [1,2,3,4,5] with left=2 and right=4, swapping nodes 2 and 4 already gives [1,4,3,2,5]. The remaining interval contains just node 3, so recursion stops. Values stay with their original nodes.

Let N be the list length and L the segment length. Repeated searches from the head give O(NL) time, or O(N²) in the worst case. Recursion uses O(L) space. The implementation assumes 1 <= left <= right <= N.
