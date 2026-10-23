# IOI '09 P3 - POI

[Source code](../../../IOI/IOI%20'09%20P3%20-%20POI.cpp) | [All IOI explanations](../README.md)

Each task is worth the number of contestants who did not solve it. The program reads the results table, counts the solvers for each task, and subtracts that count from the number of contestants. It then adds up the values of the tasks each contestant solved.

The intended ranking uses score first, then number of tasks solved, then contestant number. For contestant p, the code counts equally scoring contestants who solved more tasks in cs, and equally scoring contestants with the same solved count and a smaller number in co. Sorting the scores puts all strictly higher scores before the first occurrence of p's score. That position plus cs + co + 1 gives p's rank.

For three contestants with rows (1, 0), (1, 1), and (0, 1), both tasks are worth one point. Contestant 2 scores two points and ranks first; contestant 3 scores one point and ranks third because contestant 1 has the same score and solved count but a smaller number.

There is a special-case bug when p == 1: the final loop returns the first position with the matching score without adding cs. For rows (1, 0, 0), (0, 1, 1), and (0, 1, 1), all contestants score two points, but contestants 2 and 3 solved more tasks. Contestant 1 should rank third; this implementation prints score 2 and rank 1.

Let N be the contestant count, T the task count, and K = 2001 the allocated row width. Work is O(K² + NT + NK + N log N): the fixed table is initialized before main, and scoring copies each full K-element row before scanning its T entries. With a table sized to the input, the usual bound would be O(NT + N log N). The code allocates O(K²) table space and O(K + N) other storage. N and T must be at most 2000. Scores use int and input entries are assumed to be zero or one.
