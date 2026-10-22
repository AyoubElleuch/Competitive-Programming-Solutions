# CCC '15 S3 - Gates

[Source code](../../../CCC/CCC%20'15%20S3%20-%20Gates.cpp) | [All CCC explanations](../README.md)

Each plane is assigned the highest available gate at or below its limit. Choosing a high gate leaves smaller gates available for later planes whose limits may be more restrictive. If no eligible gate remains, docking stops.

The code converts gate limits to zero-based indices. A zero in `gates` means free; a positive value acts as a backward jump. When an occupied index is visited, the program saves its current jump, increments the stored value, and subtracts the saved jump from the index. A free index is marked occupied, and the plane count increases.

These jumps skip gates already known to be occupied. An entry initially jumps one position backward. Whenever its jump increases, the old jump has just led to another occupied gate, so extending the skipped interval is safe. For three gates and limits `[3, 3, 2]`, the selected gates are 3, 2, then 1.

This is a custom jump scheme rather than a parent-pointer disjoint set. A conservative bound is O(G + PG) time for G gates and P planes, since each search decreases its index and may inspect up to G positions. Storage is O(G). The array `gates[g+10]` has runtime size, a compiler extension rather than standard C++. Gate limits are assumed to lie between 1 and G.
