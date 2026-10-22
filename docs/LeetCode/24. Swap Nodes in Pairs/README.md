# 24. Swap Nodes in Pairs

[Source code](../../../LeetCode/24.%20Swap%20Nodes%20in%20Pairs.cpp) | [All LeetCode explanations](../README.md)

The code exchanges each adjacent pair by changing next pointers. It saves the original second node as result because that node will become the new head.

Within each iteration, prev is the pair's first node, current becomes its second node, and next saves the start of the remaining list. The second node is linked to the first. The first node is linked to the following pair's second node when that pair exists, or directly to the remaining single node or null otherwise. This prepares the connection before the next iteration rearranges that following pair.

For [1,2,3,4,5], the result is [2,1,4,3,5]. The final unpaired node stays at the end. Empty and single-node lists return immediately.

For N nodes, time is O(N) and working space is O(1). Node values are unchanged; the existing nodes are relinked. The input is assumed to be an ordinary acyclic singly linked list.
