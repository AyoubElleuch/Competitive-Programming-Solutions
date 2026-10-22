# CCCHK '15 J3 - Queens can't attack me!

[Source code](../../../CCC/CCCHK%20'15%20J3%20-%20Queens%20can't%20attack%20me!.cpp) | [All CCC explanations](../README.md)

The board begins with every square unmarked. For each queen, `fillBoard` marks its own square, its entire row and column, and the four diagonal directions leading away from it.

After processing all queens, the program counts entries that are still zero. Each such square lies outside every marked attack line, so it is a square where the queen attack rules used by this solution allow placement. Overlapping attack lines cause no double counting because marking a square simply sets it to one.

On a 3 by 3 board, a queen in the centre marks the centre, all four edge-centre squares, and all four corners. The answer is therefore zero. Larger boards can have unmarked squares outside those lines.

For M queens on an N by N board, marking each queen takes O(N) time, and the final count takes O(N²). Total time is O(MN + N²), with a fixed 101 by 101 array. The code uses 1-based coordinates and supports N up to 100. Diagonal scans continue across previously marked squares, including squares occupied by another queen; there is no obstacle or blocking check. Coordinates are assumed valid.
