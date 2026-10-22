# CCC '03 S3 - Floor Plan

[Source code](../../../CCC/CCC%20'03%20S3%20-%20Floor%20Plan.cpp) | [All CCC explanations](../README.md)

The solution first measures every room, then uses the flooring on rooms in descending order of area, as required by the problem.

`exploreRoom` is a recursive flood fill. From an unvisited floor square, it marks that square and explores its four neighbours. Walls, previously visited squares, and coordinates outside the plan contribute zero. Adding the recursive results gives the room's area. Although the outer loop calls the function for every dot, visited squares return immediately, so a room is recorded once.

After sorting the areas from largest to smallest, the program pays for each complete room while enough flooring remains. It stops when the next room is too large and prints the number completed and the leftover area. For areas `[8, 5, 2]` and 12 square metres, it covers the room of area 8, then stops with 4 left.

For R rows, C columns, and K rooms, this takes O(RC + K log K) time and O(RC + K) space including recursion. The arrays are fixed at 25 by 25. Despite its name, `inBounds` returns true for coordinates outside the plan. The flood fill assumes the input uses dots for floor and `I` for walls.
