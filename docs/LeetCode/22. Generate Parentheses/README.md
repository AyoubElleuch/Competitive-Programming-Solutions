# 22. Generate Parentheses

[Source code](../../../LeetCode/22.%20Generate%20Parentheses.cpp) | [All LeetCode explanations](../README.md)

The recursive helper builds a string while tracking how many opening and closing parentheses it has used. It adds an opening parenthesis while fewer than n have been used. It adds a closing parenthesis only when right < left, so no prefix closes more parentheses than it opens.

When both counts equal n, the string is complete and is added to the output. After exploring an appended character, the code removes it before trying another branch. Each valid sequence follows one sequence of choices, so the search produces it once.

For n=2, the two outputs are '(())' and '()()'. A prefix beginning with ')' is never generated because the closing-parenthesis condition fails at the start.

Let Cn be the number of valid outputs, the nth Catalan number. A conservative time bound for this implementation is O(n² Cn), accounting for up to O(n Cn) explored prefixes and O(n) string-copy cost per recursive call. Output storage is O(n Cn). Because each call receives its own string copy, active calls can use O(n²) additional space. For n=0, it returns one empty string.
