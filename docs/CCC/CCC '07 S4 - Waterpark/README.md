# CCC '07 S4 - Waterpark

[Source code](../../../CCC/CCC%20'07%20S4%20-%20Waterpark.cpp) | [All CCC explanations](../README.md)

The input edges are stored backwards. For a slide from a to b, the code adds a to `v[b]`. This lets `explore(n)` count routes into the final point by asking how many routes reach each predecessor.

Point 1 has one route to itself. Every other point sums the counts of its incoming neighbours and saves the result in `dp`. A route into a point must arrive through one of those incoming slides, so adding their counts gives the total. For slides `1 -> 2`, `1 -> 3`, `2 -> 4`, and `3 -> 4`, the result at 4 is `1 + 1 = 2`.

The recursion relies on the downhill graph being acyclic. There is no active-recursion marker to detect a cycle. Counts use `int`, and the vectors reserve 10010 entries, so labels and route totals must fit those limits.

With proper caching of zero counts, this recurrence would take O(V + E) time. Here, `dp[n] != 0` recognizes positive cached counts but recomputes unreachable states whose answer is zero. Shared zero-result subgraphs can therefore cause exponentially many recursive calls. Space is O(10010 + E), including the fixed vectors and a recursion stack bounded by the graph's depth.
