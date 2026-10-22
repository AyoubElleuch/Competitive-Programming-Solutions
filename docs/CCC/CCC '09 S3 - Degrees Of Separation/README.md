# CCC '09 S3 - Degrees Of Separation

[Source code](../../../CCC/CCC%20'09%20S3%20-%20Degrees%20Of%20Separation.cpp) | [All CCC explanations](../README.md)

An adjacency matrix represents the friendship network: `adj[x][y] = 1` means x and y are friends. Insertions and deletions update both directions, and the program begins with the friendships listed in the source.

The `n` command counts set entries in a person's row. The `f` command checks the friends of each direct friend, excluding the person and their existing friends. A temporary marker ensures that someone found through two mutual friends is counted once.

For `s x y`, the code searches one breadth-first layer at a time. It first checks whether a person in the current layer is directly connected to y. The first successful layer gives the number of friendship links. If the search runs out of people, it prints `Not connected`.

For a matrix with V labels, updates take O(1), direct-friend queries O(V), and friends-of-friends queries O(V²). A conventional matrix BFS takes O(V²), but this version marks a vertex when processing it and does not skip duplicate entries already queued. Repeated entries can multiply across layers, so that bound does not apply to this implementation. The matrix has 51 rows and columns. Also, a query from x to itself is not handled as distance zero; it may report a positive cycle length or no connection.
