# 234. Palindrome Linked List

[Source code](../../../LeetCode/234.%20Palindrome%20Linked%20List.cpp) | [All LeetCode explanations](../README.md)

The solution first copies every list value into a vector. It then compares entries from the two ends, advancing inward until the indices meet or cross.

If any mirrored pair differs, the list is not a palindrome and the function returns false. If every pair matches, reading the values forward or backward gives the same sequence. Copying values makes those mirrored positions directly accessible without changing any list links.

For [1,2,2,1], the comparisons are 1 with 1 and 2 with 2, so the result is true. For [1,2], the first comparison fails. An odd-length list compares its centre value with itself, which is harmless. Empty input returns true immediately.

For N nodes, building the vector and comparing it take O(N) total time. The vector uses O(N) extra space. The method checks equality of values, so different nodes containing equal values match. It assumes the list is acyclic and leaves it unchanged.
