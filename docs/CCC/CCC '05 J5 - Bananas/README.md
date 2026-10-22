# CCC '05 J5 - Bananas

[Source code](../../../CCC/CCC%20'05%20J5%20-%20Bananas.cpp) | [All CCC explanations](../README.md)

The code checks a word by reading its first grammatical unit and recursively checking what remains. A monkey word consists of an A-word, optionally followed by `N` and another monkey word. An A-word is either `A` or `B` + monkey word + `S`.

`solve` accepts the single letter `A`. If a longer string starts with `AN`, it checks the suffix after those letters. If it starts with `B`, the helper `find` counts nested B and S characters until it finds the matching S. The inside must be valid; after the S, the string must end or contain `N` followed by another valid word.

For example, `BASNA` is accepted: `BAS` encloses `A`, then `N` joins it to another `A`. An unmatched B or an invalid suffix causes rejection. Input continues until `X`.

For a word of length L, repeated scans and substring copies can take O(L²) time. Nested recursive calls retain copied strings, giving O(L²) worst-case space and O(L) recursion depth. When a matching S ends the string, `s[i+1]` reads the string's terminating null character before the empty-suffix check. The implementation depends on valid string access at `size()`; explicitly checking the suffix length would make that case easier to read.
