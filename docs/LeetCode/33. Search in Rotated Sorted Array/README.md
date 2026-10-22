# 33. Search in Rotated Sorted Array

[Source code](../../../LeetCode/33.%20Search%20in%20Rotated%20Sorted%20Array.cpp) | [All LeetCode explanations](../README.md)

Binary search is adapted to an ascending array that has been rotated. After checking the midpoint, the code determines which half is still sorted.

If nums[left] <= nums[pivot], the left half is sorted. The target's value tells whether it can lie within that half; otherwise, the search continues to the right. If the left half is not sorted, the right half is, and the code makes the corresponding range check there. The midpoint is removed from further consideration after each unsuccessful check.

For [4,5,6,7,0,1,2] and target 0, the initial midpoint is 7. The left half is sorted but its range excludes 0, so the search continues in [0,1,2]. Missing targets return -1.

For N elements, time is O(log N) and space is O(1). Distinct values are required for the sorted-half test to identify a safe half to discard. Duplicate values can make that test ambiguous; this file does not contain the duplicate-handling branch used in problem 81.
