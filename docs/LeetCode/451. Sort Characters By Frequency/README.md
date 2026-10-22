# 451. Sort Characters By Frequency

[Source code](../../../LeetCode/451.%20Sort%20Characters%20By%20Frequency.cpp) | [All LeetCode explanations](../README.md)

The function counts each character, then stores it in the bucket matching its frequency. Scanning those buckets from the largest index down gives characters in decreasing occurrence count.

For each character in bucket i, the code appends it i times. This keeps all occurrences of a character together. For 'tree', the two e characters are emitted first, followed by r and t in either order. Both 'eert' and 'eetr' satisfy the frequency ordering.

Characters with equal frequencies inherit the iteration order of the unordered_map, so the function does not promise an alphabetical tie-break. Uppercase and lowercase characters are distinct map keys.

For N input characters, expected time is O(N), including frequency counting, bucket scanning, and amortized string appends. The N+1 bucket headers and result require O(N) space; the map also stores the distinct characters. The input parameter is passed by value, adding a string copy. The implementation works with char units rather than decoding Unicode code points, so multibyte text is handled byte by byte.
