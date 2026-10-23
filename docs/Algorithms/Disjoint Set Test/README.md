# Disjoint Set Test

[Source code](../../../Algorithms/Disjoint%20Set%20Test.cpp) | [All Algorithms explanations](../README.md)

The program builds a spanning tree by reading edges in their input order. Each vertex starts in its own disjoint set. An edge is accepted when its endpoints have different representatives; joining those sets connects two components without creating a cycle.

The parent function follows v until it reaches a root. fusion attaches the smaller set to the larger set, using r as the set size. There is no path compression. Union by size limits tree height because a vertex's depth increases only when its set joins a set at least as large.

Accepted edge numbers are stored in ans. The variable nodes starts at 1 and increases once per accepted edge, so it means accepted-edge count plus one. Reaching n means n - 1 edges were accepted. Since every accepted edge joined different components, those edges form a spanning tree. Otherwise the program prints Disconnected Graph.

For vertices 1, 2, 3 and edges (1, 2), (2, 3), (1, 3), it prints edge numbers 1 and 2 on separate lines. The third edge is skipped because its endpoints are already connected. Edges are not sorted by weight; this finds a spanning tree in input order, not a minimum-weight tree.

With N vertices and M edges, each representative search costs O(log N). Processing costs O(M log N), plus initialization of K = 100001 entries. Storage is O(K + N), including at most N - 1 accepted edge numbers. Vertices are assumed to be numbered from 1 to N with N <= 100000. Self-loops and repeated edges are skipped when their representatives match.
