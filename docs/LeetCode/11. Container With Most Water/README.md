# 11. Container With Most Water

[Source code](../../../LeetCode/11.%20Container%20With%20Most%20Water.cpp) | [All LeetCode explanations](../README.md)

Two pointers begin at the first and last heights. Their distance is the container's width, and the shorter wall limits its height. The code computes that area and keeps the largest one seen.

It then moves the pointer at the shorter wall inward. Keeping that wall while reducing the width cannot improve the current area, even if the other wall becomes taller. Any better pair must therefore discard the shorter wall. When both heights are equal, the code moves the right pointer; the same reasoning permits discarding either end.

For [1,8,6,2,5,4,8,3,7], the walls of height 8 and 7 at indices 1 and 8 give width 7 and area 49. The search considers that pair as it narrows the interval.

For N heights, time is O(N), since one pointer moves on every iteration. Space is O(1), and the input is unchanged. The area is stored as int, so height times width must fit that type. The problem supplies at least two non-negative heights.
