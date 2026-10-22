# CCC '07 J4 - Anagram Checker

[Source code](../../../CCC/CCC%20'07%20J4%20-%20Anagram%20Checker.cpp) | [All CCC explanations](../README.md)

The program reads both lines, tries to remove spaces, then matches letters by deleting them from the second string. Each character of the first string searches for one equal character in the remaining second string. Deleting a match prevents that occurrence from being reused.

For `ABC` and `BCA`, processing A leaves `BC`, processing B leaves `C`, and processing C leaves an empty string. The final check prints `Is an anagram.` when the second string is empty.

There are two limits to that check. An unmatched character in the first string does not cause failure, so `AA` and `A` are incorrectly accepted. Also, the space-removal loops increment their index after erasing a character. Consecutive spaces can therefore be skipped because the next space shifts into the erased position.

With line lengths A and B, scanning for matches and shifting characters during erasures takes O(A² + B² + AB) worst-case time, or O(L²) when both lengths are bounded by L. The strings use O(A + B) space. Matching is case-sensitive and removes literal spaces rather than general whitespace. These notes describe the submitted implementation; a frequency-count comparison would need different code.
