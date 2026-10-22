# CCC '10 J5 - Knight Hop

[Source code](../../../CCC/CCC%20'10%20J5%20-%20Knight%20Hop.cpp) | [All CCC explanations](../README.md)

The chessboard is treated as an unweighted graph. Each square is a vertex, and each legal knight move is an edge. A breadth-first search finds how many moves separate the starting and ending squares.

`bfs` stores every square at the current distance. For each square, the code tries all eight combinations of one step in one direction and two in the other. `inBounds` rejects squares outside coordinates 1 through 8 or already visited. `exploreBoard` marks a square when adding it to the next layer, which prevents duplicate entries.

After processing a layer, the program replaces it with `newNode` and increments `counter`. The first time the destination is processed, all shorter distances have already been checked. If the start equals the destination, it prints zero; moving from `(1,1)` to `(2,3)` takes one move.

There are 64 squares and at most eight checks per square, so time and space are O(64), or O(1) for this fixed board. On an N by N board, the same method would use O(N²) time and space. The arrays and coordinate checks in this file are specific to an 8 by 8 board and assume valid input coordinates.
