# 347. Top K Frequent Elements

[Source code](../../../LeetCode/347.%20Top%20K%20Frequent%20Elements.cpp) | [All LeetCode explanations](../README.md)

The code counts each value with an unordered_map, then groups values into buckets indexed by frequency. Bucket f contains values that occur f times. No frequency can exceed the array length, so N+1 buckets are sufficient.

It scans the buckets from highest frequency to lowest and appends their values until the result contains k elements. Every value in a bucket visited earlier is at least as frequent as a value visited later, so the collected elements are the most frequent ones.

For [1,1,1,2,2,3] with k=2, buckets 3, 2, and 1 contain 1, 2, and 3 respectively. The scan returns [1,2]. Values with the same frequency follow unordered_map iteration order; their relative order is not specified.

For N input values, expected time is O(N), using expected constant-time hash operations. Hash collisions can worsen that bound. The buckets, frequency map, and result use O(N) space. The implementation assumes 1 <= k <= the number of distinct values. In particular, k=0 is not handled as a request for an empty result.
