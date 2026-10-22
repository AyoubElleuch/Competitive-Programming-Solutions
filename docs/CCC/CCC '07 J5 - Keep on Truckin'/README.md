# CCC '07 J5 - Keep on Truckin'

[Source code](../../../CCC/CCC%20'07%20J5%20-%20Keep%20on%20Truckin'.cpp) | [All CCC explanations](../README.md)

The vector starts with the supplied motel positions, including 0 and 7000. Extra motels are appended, and sorting puts every possible stop in travel order.

`ways(i)` counts trips from motel i to the destination. It tries each later motel j whose distance satisfies `a <= v[j] - v[i] <= b`, then adds `ways(j)`. Reaching the last position contributes one completed trip. Each route has a particular next motel, so summing over those choices counts the routes without merging different stopping sequences.

For a small example with positions `[0, 3, 6]` and daily distances from 3 through 6, there are two routes: go directly to 6, or stop at 3 first. The code applies the same recurrence to the full motel list.

Positive results are cached by index. However, `if(dp[i])` treats a cached zero as uncomputed, so dead ends are searched again. If zero-result states were cached properly, the search would take O(M²) time for M motels; this version can take exponential time on inputs with many repeated unsuccessful continuations. Sorting takes O(M log M), and storage plus recursion uses O(M). Counts use `long long` and can overflow outside its range. The destination check assumes the largest motel position is 7000.
