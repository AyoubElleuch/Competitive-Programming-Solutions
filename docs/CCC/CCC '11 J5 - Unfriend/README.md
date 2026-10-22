# CCC '11 J5 - Unfriend

[Source code](../../../CCC/CCC%20'11%20J5%20-%20Unfriend.cpp) | [All CCC explanations](../README.md)

The solution counts deletion choices from the leaves upward without building an explicit tree. The input gives the inviter of each person i, and the inviter has a larger number. Processing people in increasing order therefore finishes a person's descendants before updating their inviter.

`dp[i]` starts at one. By the time person i is processed, it represents the ways to choose deletions among i's descendants while keeping i. The code increments it to include one more choice: remove i and their entire invited group. It then multiplies that count into `dp[tmp]`, where tmp is i's inviter.

Multiplication works because choices for separate invited groups are independent. If the final person invited two leaves, each leaf can either stay or be removed, giving `2 * 2 = 4` choices. If those people form a chain instead, removing someone also removes their descendants, so the recurrence counts three choices rather than four.

The last person is kept, so the code prints `dp[n]` without adding a removal option for n. It takes O(N) time. The vector has exactly seven entries, supporting the problem's small limit of at most six people with 1-based indexing. Counts are stored as `int`; larger instances would need both larger storage and an appropriate count type.
