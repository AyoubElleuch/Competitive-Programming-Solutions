# CCC '20 S2 - Escape Room

[Source code](../../../CCC/CCC%20'20%20S2%20-%20Escape%20Room.cpp) | [All CCC explanations](../README.md)

From a cell with value v, the allowed destinations are coordinates `(r, c)` satisfying `r * c = v`. The program prepares those destinations while reading the grid: `adj[r*c]` stores every cell with that coordinate product.

A queue then performs breadth-first search from `(1,1)`. For each current cell, the program looks up the bucket indexed by its value and schedules destinations that have not been visited. Marking them when scheduled prevents duplicate queue entries. Reaching the bottom-right cell prints `yes`; exhausting the queue prints `no`.

For example, a value of 6 allows destinations such as `(2,3)` and `(3,2)`, provided those coordinates exist in the grid. Precomputing buckets avoids factoring the value separately at every cell. Every scheduled jump satisfies the product rule, and every permitted destination appears in its bucket.

Let K = R*C, B = 1000100, and b(v) be the size of bucket v. Time is O(B + K + sum b(value(cell))) over visited cells. Buckets are not cleared after use, so equal values cause repeated scans; O(B + K²) is a conservative upper bound. Space is O(B + K). Both coordinate products and cell values must be valid indices below B. The code assumes positive dimensions and input values within those bounds.
