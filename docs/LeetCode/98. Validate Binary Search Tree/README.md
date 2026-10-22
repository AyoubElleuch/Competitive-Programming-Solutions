# 98. Validate Binary Search Tree

[Source code](../../../LeetCode/98.%20Validate%20Binary%20Search%20Tree.cpp) | [All LeetCode explanations](../README.md)

Each queued node is paired with a lower and upper bound inherited from its ancestors. The root begins between LLONG_MIN and LLONG_MAX.

The node's value must be strictly inside its bounds. Its left child inherits the lower bound and uses the current value as its upper bound. Its right child uses the current value as its lower bound and inherits the upper bound. These restrictions check the entire ancestor chain, so a node can fail even when its immediate parent relationship looks valid.

For a root 5 with right child 7 and a left child 4 under 7, the value 4 fails its inherited lower bound of 5. Duplicate values also fail because the comparisons are strict. Bounds use long long, allowing nodes with INT_MIN or INT_MAX values.

For N nodes, time is O(N). The breadth-first queue uses O(W) space for maximum tree width W, which can be O(N). An empty tree returns true. The implementation uses C++17 structured bindings and leaves the tree unchanged.
