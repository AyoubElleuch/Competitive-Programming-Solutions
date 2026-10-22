# 74. Search a 2D Matrix

[Source code](../../../LeetCode/74.%20Search%20a%202D%20Matrix.cpp) | [All LeetCode explanations](../README.md)

The search has two stages. First, it binary-searches the first value of each row to select the last row whose first value is at most the target. An upper midpoint ensures progress when the left bound is kept at pivot.

The second stage binary-searches within that row. After checking the midpoint, it keeps the left half when the target lies between the current left value and the midpoint value; otherwise it keeps the right half. A target below the entire matrix may still select row zero, but the row search returns false.

For [[1,3,5],[7,9,11]], target 9 selects the second row and is found there. Target 6 selects the first row and is absent.

For M rows and N columns, time is O(log M + log N) and space is O(1). The matrix must be nonempty, with nonempty sorted rows, and each row's first value must be greater than the previous row's last value. Sorting rows independently without this cross-row order would not justify choosing a single row.
