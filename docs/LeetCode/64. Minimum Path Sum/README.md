# 64. Minimum Path Sum

[Source code](../../../LeetCode/64.%20Minimum%20Path%20Sum.cpp) | [All LeetCode explanations](../README.md)

The recursive helper computes the cheapest path from the top-left square to a requested square. Since moves are right or down, the last step must come from above or from the left.

For each valid predecessor, the code adds the current cell's cost to that predecessor's minimum path sum. It takes the smaller candidate and stores it in sums. The starting square returns its own cost, so every path includes both endpoints. A predecessor outside the grid is represented by INT_MAX and is not added to a cell cost.

For [[1,3,1],[1,5,1],[4,2,1]], the route across the top and down the right side costs 1+3+1+1+1=7. Memoization lets different recursive branches reuse their shared predecessor results.

Under the problem's cost bounds, time is O(MN), memo space is O(MN), and recursion depth is O(M+N). The grid must be nonempty and rectangular. All sums must fit int and stay below the INT_MAX marker; a legitimate result equal to that marker would be treated as uncomputed on later calls.
