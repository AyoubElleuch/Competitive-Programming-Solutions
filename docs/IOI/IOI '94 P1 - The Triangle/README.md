# IOI '94 P1 - The Triangle

[Source code](../../../IOI/IOI%20'94%20P1%20-%20The%20Triangle.cpp) | [All IOI explanations](../README.md)

A path starts at the triangle's top and takes one of the two adjacent entries in the next row. The recursive function returns the largest sum available from its current cell through the bottom.

In maxSum(x, level, index), x is the current cell's value, level is the next row to visit, and index is the current column. The two recursive calls choose v[level][index] and v[level][index + 1]. The function adds the larger continuation to x. Once level reaches n, there is no next row and it returns x.

Every downward path must choose one of those two children. Taking the larger of their optimal continuations therefore gives the optimal continuation from the current cell. For rows (5), (2, 4), and (1, 3, 2), the answer is 12 from the path 5, 4, 3.

The memoization key is the string x,level,index. Including x is redundant for valid calls, since a cell's position already determines its value. The check if(dp[d]) reuses a saved answer only when it is nonzero. A zero result is recomputed, so an all-zero triangle still creates an exponential recursion tree.

For nonzero cached subproblem results and expected hash performance, there are O(n²) states and O(n²) work if integer-to-string conversion and key hashing are treated as bounded operations. More explicitly, a key has O(log V + log n) characters for bounded integer magnitude V. With zero results, recursive calls can grow to O(2^n), with key-processing cost in addition. The triangle and memo table store O(n²) entries, and recursion depth is O(n). Keys also require their string storage.

The code assumes n >= 1 and uses int for values and sums. Negative values are handled by the recurrence, but a computed sum must fit in int. The program prints the maximum sum, without reconstructing the path.
