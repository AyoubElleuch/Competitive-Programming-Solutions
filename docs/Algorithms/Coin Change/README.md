# Coin Change

[Source code](../../../Algorithms/Coin%20Change.cpp) | [All Algorithms explanations](../README.md)

The function minchange(value) tries every denomination as the next coin. Subtracting that coin leaves a smaller amount to solve. It adds one to the answer for that remainder and saves the smallest candidate in dp.

A remainder of zero needs zero coins. A negative remainder returns -1 through the unsigned return type, producing the largest unsigned value. Adding one wraps it to zero, which the next > 0 test rejects. This relies on unsigned arithmetic rather than a separate impossible-state flag.

Trying every first coin includes an optimal solution whenever the amount is reachable. For target 6 and denominations 1, 3, and 4, choosing 3 leaves 3, so the minimum is two coins. With target 3 and denomination 2, no candidate succeeds and the program prints its sentinel 10001.

For target X and C positive integer denominations, there are at most X positive remainder states. With expected O(1) hash operations, time is O(XC), memo storage is O(X), the coin list uses O(C), and recursion depth can be O(X). The code does not sort or deduplicate the coins.

All denominations must be positive. A zero coin recurses on the same uncached state; a negative coin can increase the remainder indefinitely. The initial minimum is 10001, so solutions requiring more than 10001 coins are not represented correctly, and an answer of 10001 is indistinguishable from failure. This implementation prints that sentinel rather than a conventional -1 for an unreachable amount.
