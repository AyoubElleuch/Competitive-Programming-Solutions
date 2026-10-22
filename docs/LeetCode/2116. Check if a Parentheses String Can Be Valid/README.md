# 2116. Check if a Parentheses String Can Be Valid

[Source code](../../../LeetCode/2116.%20Check%20if%20a%20Parentheses%20String%20Can%20Be%20Valid.cpp) | [All LeetCode explanations](../README.md)

The function first rejects odd lengths because a balanced parentheses string needs an equal number of opening and closing characters. It then tracks lower and upper bounds on the number of unmatched opening parentheses after each prefix.

A locked opening parenthesis increases both bounds, and a locked closing parenthesis decreases both. An unlocked position can be either character, so it decreases the lower bound and increases the upper bound. If the upper bound becomes negative, even the choice with the most opening parentheses cannot balance the prefix, so the function returns false. The lower bound is clamped to zero.

At the end, a zero lower bound indicates that balance can be reached. For '))' with both positions unlocked, choosing '()' succeeds. A locked ')' at the first position fails immediately. The bounds summarize possible balances; parity is handled by the even-length check and one-character transitions.

For N characters, time is O(N) and working space is O(1). Both strings are passed by value, which can add O(N) copying space. They must have equal lengths, with locked containing only '0' and '1'.
