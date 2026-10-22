# 42. Trapping Rain Water

[Source code](../../../LeetCode/42.%20Trapping%20Rain%20Water.cpp) | [All LeetCode explanations](../README.md)

The code scans inward from both ends while tracking maxLeft and maxRight, the tallest walls already processed on each side. At each step, it processes the side with the lower current height.

If that height is below its side's recorded maximum, the difference is added to trapped_water. Otherwise, it becomes the new maximum. Processing the lower side is safe because the opposite side supplies a sufficient boundary for the amount being counted; a still-unknown taller wall cannot reduce that amount. The algorithm's inward scan preserves this boundary property as the pointers advance.

For [2,0,2], the middle square has a wall of height 2 on both sides, so it contributes two units. Flat or steadily increasing heights contribute zero.

For N bars, time is O(N) and working space is O(1). The input is unchanged, and heights are assumed non-negative. The water total uses int, so the accumulated volume must fit that type. The scan ends when the pointers meet because the remaining position cannot add unaccounted water under the maintained boundaries.
