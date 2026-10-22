# CCC '12 S5 - Mouse Journey

[Source code](../../../CCC/CCC%20'12%20S5%20-%20Mouse%20Journey.cpp) | [All CCC explanations](../README.md)

The table `dp[i][j]` counts paths to a square. The mouse can travel right or down, so processing the grid row by row ensures that a square has received its contributions before passing them onward.

The start is assigned one path. Each square adds its current count to its right and lower neighbours, provided those neighbours do not contain cats. A cat square is assigned zero instead. Every path into a square has a final step from above or from the left, so these additions count the possible paths.

On a 2 by 2 empty grid, the two routes are right-then-down and down-then-right. Blocking the upper-right square leaves one route. The answer is the bottom-right table entry.

For R rows, C columns, and K cat positions, time is O(RC + K), plus initialization of the 25 by 25 tables. The implementation reserves O(25 * 25) space and assumes both dimensions are at most 25. Path counts use `int`, so sufficiently large totals overflow. The start is seeded before cat positions are read and is never cleared if a cat occupies it. The implementation therefore assumes the starting square is free.
