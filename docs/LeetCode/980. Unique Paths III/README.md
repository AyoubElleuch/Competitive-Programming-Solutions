# 980. Unique Paths III

[Source code](../../../LeetCode/980.%20Unique%20Paths%20III.cpp) | [All LeetCode explanations](../README.md)

The solution uses backtracking to try walks that visit every non-obstacle square exactly once. It locates the start and destination and initializes empty to the number of ordinary empty squares plus one for the start. The destination is excluded from that count.

At a square, obstacles and previously visited positions return zero. At the destination, a route counts only if empty is zero. Otherwise, the square is marked visited and the helper explores its four neighbours with empty-1. Before returning, it unmarks the square so another candidate route can use it.

For the one-row grid [1,0,2], the remaining count goes from two at the start to one at the middle square and zero at the destination, yielding one route. Reaching the destination too early contributes nothing because some required squares remain unvisited.

For K walkable squares, the search is exponential; O(RC + 4^K) is a conservative time bound. The visited table uses O(RC) space and recursion uses O(K). The grid is unchanged. The code assumes a nonempty rectangular grid with exactly one start and one destination.
