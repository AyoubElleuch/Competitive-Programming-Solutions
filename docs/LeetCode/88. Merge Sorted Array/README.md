# 88. Merge Sorted Array

[Source code](../../../LeetCode/88.%20Merge%20Sorted%20Array.cpp) | [All LeetCode explanations](../README.md)

The implementation merges into a temporary vector. Two indices track the unconsumed portions of nums1 and nums2. The code repeatedly appends the smaller front value and advances that input's index.

Only the first m entries of nums1 are treated as input values; its spare trailing positions are ignored. Once either input is exhausted, the remaining values from the other are appended. Finally, assigning sorted to nums1 replaces its contents with the merged sequence.

For nums1=[1,2,3,0,0,0], m=3, nums2=[2,5,6], and n=3, the result is [1,2,2,3,5,6]. Each chosen value is no larger than any unconsumed value, so the output remains sorted. Ties take the value from nums2 first.

Time is O(M+N), and the temporary vector uses O(M+N) extra space. The implementation uses an additional buffer even though the destination already has room. Both input prefixes are assumed sorted, with valid lengths; nums2 is unchanged.
