# 62. Unique Paths

[Source code](../../../LeetCode/62.%20Unique%20Paths.cpp) | [All LeetCode explanations](../README.md)

The recursive helper counts routes from a square to the bottom-right corner. It can continue one square down or one square right, and adds the counts from those valid moves.

Reaching the destination contributes one completed route. Other results are stored in grid, which serves as a memo table. A route has a particular first move, so adding the down and right possibilities counts all routes without counting the same move sequence twice.

For a 2 by 3 grid, the three routes are right-right-down, right-down-right, and down-right-right. The recursive calls share smaller suffix problems, and memoization prevents repeatedly calculating those counts.

Time is O(MN) for M rows and N columns. The memo table uses O(MN) space, and the recursion stack can reach O(M+N) depth. Zero means uncomputed here; every square in a positive-sized obstacle-free grid has a positive route count, so that marker works. Dimensions must be positive, and path counts must fit int. Very long, narrow grids can also exceed practical recursion depth.
