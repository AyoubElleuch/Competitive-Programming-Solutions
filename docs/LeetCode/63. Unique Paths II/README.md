# 63. Unique Paths II

[Source code](../../../LeetCode/63.%20Unique%20Paths%20II.cpp) | [All LeetCode explanations](../README.md)

This solution counts paths backwards from the destination. To reach square (r,c), the previous square must be directly above or directly to the left. The helper adds the route counts from those two predecessors.

An obstacle returns zero before any other checks, so blocked starting and ending squares are handled. The unblocked starting square returns one. Computed values go into a separate memo table initialized to -1, allowing zero-path results to be cached too.

For a 3 by 3 grid with only its centre blocked, the answer is two: travel around the obstacle along the top and right edges, or along the left and bottom edges. Every counted path ends with exactly one of the predecessor moves used in the recurrence.

Time is O(MN), with O(MN) memo storage and O(M+N) recursion depth. The obstacle grid is unchanged. The code reads obstacleGrid[0] and assumes a nonempty rectangular grid with at least one column. Path counts use int and must remain within its range.
