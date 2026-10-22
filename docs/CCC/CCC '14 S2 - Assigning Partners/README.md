# CCC '14 S2 - Assigning Partners

[Source code](../../../CCC/CCC%20'14%20S2%20-%20Assigning%20Partners.cpp) | [All CCC explanations](../README.md)

The two input rows describe proposed partners at matching indices. A valid assignment must pair distinct people and be reciprocal: if A is assigned B, B must be assigned A.

The program rejects an odd number of people immediately. For each `first[i]`, it searches for that name in the second row. Suppose it is found at position j. Then person `first[j]` has chosen `first[i]`, so the code checks that `first[j] == second[i]`. It also rejects `j == i`, which would pair a person with themselves.

For rows `[Alice, Bob]` and `[Bob, Alice]`, Alice appears at position 1 in the second row, and the first row at that position is Bob. Both reciprocal checks succeed. A cycle of length three fails because the partner relationship does not return to the original person.

There are N linear searches, giving O(N²) name comparisons and O(N) stored names. String comparisons also depend on name length. The implementation assumes the rows contain the same set of unique names. If a name is absent from the second row, `find` returns the end iterator and the code accesses `first[n]`, which is outside the vector. That malformed-input case is not checked.
