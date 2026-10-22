# 81. Search in Rotated Sorted Array II

[Source code](../../../LeetCode/81.%20Search%20in%20Rotated%20Sorted%20Array%20II.cpp) | [All LeetCode explanations](../README.md)

The code binary-searches a rotated ascending array while allowing duplicates. It first checks the midpoint. If both ends and the midpoint have equal values, it cannot determine which half contains the rotation, so it removes one element from each end and continues.

That removal is safe because the midpoint comparison has already shown that this repeated value is not the target. Otherwise, the code identifies a sorted half and checks whether the target lies in its value range, as in the distinct-value version.

For [1,0,1,1,1] with target 0, equal boundary values initially hide which half is sorted. Shrinking the boundaries eventually exposes the part containing 0. The function returns a boolean rather than an index.

Time is O(log N) when the search can repeatedly discard halves, but O(N) in the worst case when duplicates force boundary-by-boundary shrinking. Working space is O(1), and the array is unchanged. The input must be a rotation of a nondecreasing array.
