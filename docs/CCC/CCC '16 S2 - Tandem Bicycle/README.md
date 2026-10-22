# CCC '16 S2 - Tandem Bicycle

[Source code](../../../CCC/CCC%20'16%20S2%20-%20Tandem%20Bicycle.cpp) | [All CCC explanations](../README.md)

A tandem bicycle travels at the faster rider's speed. The program sorts the two groups and pairs riders by index, adding `max(dmoj[i], peg[i])` for each bicycle.

For the minimum total, both lists are sorted in ascending order. This pairs riders of similar rank, putting fast riders together so their speeds do not increase separate bicycle totals. For the maximum, one list is ascending and the other descending, pairing fast riders with slower partners.

For groups `[1, 4]` and `[2, 3]`, matching sorted positions gives `max(1,2) + max(4,3) = 6`. Opposite orders give `max(1,3) + max(4,2) = 7`. Comparing the two pairings of any two sorted riders shows that matching ranks cannot increase the minimum sum; reversing ranks cannot decrease the maximum sum. Repeating those pair exchanges gives the sorted arrangements.

Sorting dominates the O(N log N) time; summing the pair speeds takes O(N). The two input vectors use O(N) space, with sorting performed in place. Speeds and the sum use `int`, so their total must fit. Mode 1 selects the minimum; any other mode selects the maximum.
