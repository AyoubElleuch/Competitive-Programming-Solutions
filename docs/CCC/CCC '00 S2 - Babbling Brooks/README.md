# CCC '00 S2 - Babbling Brooks

[Source code](../../../CCC/CCC%20'00%20S2%20-%20Babbling%20Brooks.cpp) | [All CCC explanations](../README.md)

The program keeps the streams in a vector, in their left-to-right order. A split or a join changes that vector immediately, so later commands use the updated stream numbers.

For command `99 a p`, it computes `p` percent of stream `a` and inserts that amount just before the old stream. The old stream shifts one position to the right, and subtracting the inserted amount leaves its remaining flow. Command `88 a` adds the next stream into stream `a`, then erases the next entry. Command `77` ends the simulation.

For example, splitting a flow of 100 at 30 percent produces `[30, 70]`. Joining those two streams produces `[100]` again. Both operations preserve total flow, apart from floating-point rounding.

With at most S streams present and Q commands, vector insertions and erasures give O(QS) time, plus input and output, and O(S) space. Flows are stored as `float`, but the final loop reads each as an `int`, so fractional parts are truncated rather than rounded. Stream indices are assumed valid.
