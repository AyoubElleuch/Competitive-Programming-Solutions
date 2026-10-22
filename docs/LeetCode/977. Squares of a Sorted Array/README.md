# 977. Squares of a Sorted Array

[Source code](../../../LeetCode/977.%20Squares%20of%20a%20Sorted%20Array.cpp) | [All LeetCode explanations](../README.md)

Although the input is sorted, squaring can reverse the order of negative values. The largest remaining absolute value must be at one of the current ends, so the code compares those ends and writes the larger square into the last unfilled output position.

It advances the selected endpoint and moves the output index left. When the endpoints meet, one input value remains and its square is written at result[0]. Filling from the back keeps all previously written entries at least as large as those still to come.

For [-4,-1,0,3,10], the selected squares begin 100,16,9,1, leaving zero for the first slot. The final output is [0,1,9,16,100]. Equal absolute values may be taken from the right first without affecting sorted order.

For N elements, time is O(N) and output storage is O(N), with O(1) working space beyond it. The input must be sorted and nonempty: the final assignment accesses result[0] and nums[p1]. Squaring and abs must be safe for the int values supplied.
