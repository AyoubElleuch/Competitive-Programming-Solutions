# CCC '11 J4 - Boring Business

[Source code](../../../CCC/CCC%20'11%20J4%20-%20Boring%20Business.cpp) | [All CCC explanations](../README.md)

The program marks the pre-existing tunnel in a grid and starts at `(-1, -5)`. For each command, it advances one unit at a time, checking every square along the requested segment.

The input coordinates are translated into array indices with `grid[-(row+1)][col+200]`. This maps negative vertical coordinates and possibly negative horizontal coordinates into the allocated array. A previously marked square sets `safe` to zero; otherwise the new square is marked as drilled.

After finishing the command's distance, the program prints the final horizontal and vertical coordinates followed by `safe` or `DANGER`. Checking intermediate squares catches a collision even when the endpoint itself was unoccupied. Once danger has occurred, the outer loop ends, although the inner loop still completes that command.

If T is the total distance simulated, time is O(200 * 401 + T), including grid initialization. The fixed grid uses O(200 * 401) space. There is no bounds check before indexing: the allocated coordinates correspond to x from -200 through 200 and y from -200 through -1. Input must stay within that range. Directions l, r, and u have explicit branches; other non-quit directions are treated as down.
