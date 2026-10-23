# Ternary Search Tree

[Source code](../../../Algorithms/Ternary%20Search%20Tree.cpp) | [All Algorithms explanations](../README.md)

Each node stores an integer and three child pointers. A smaller value follows child 0, an equal value follows child 1, and a larger value follows child 2. The comparison is repeated at every node until an empty pointer is found.

The first inserted value becomes Root and produces no output. Each later insertion prints the value of its immediate parent when it is attached. addNode handles the root comparison, and addNodeAt recursively handles the remaining comparisons.

For input values (5, 3, 5, 7, 4), the printed parent values are 5, 5, 5, and 3, each on its own line. The duplicate 5 uses the equality child of the root, while 4 follows the smaller branch to 3 and then its larger branch. This tree stores integers; it is not the character-based ternary search tree used for string lookup.

One insertion costs O(h), where h is the current height. The tree is not balanced: sorted values or repeated equal values can create a chain. Building N nodes can therefore take O(N²) time in the worst case, with O(N) node storage and O(N) recursive stack depth. The code has no lookup, deletion, rebalancing, or destructor; allocated nodes are not explicitly freed before program exit.
