# Sudoku Challenge

[Source code](../../../Algorithms/Sudoku%20Challenge.cpp) | [All Algorithms explanations](../README.md)

The solver reads a nine-by-nine grid, treating a dot as an empty cell and a digit as a fixed entry. It visits cells in row order and tries digits 1 through 9 in each empty cell.

isSafe checks the candidate against its row, column, and three-by-three box. If it fits, solveSudoku assigns it and recursively tries the next cell. A failed continuation resets the cell to zero before trying the next digit. Fixed cells are skipped. The first completed grid stops the search and is printed as nine rows of digits.

For a valid completed grid with just the first cell replaced by a dot, that cell's row, column, and box exclude the other eight digits. The solver restores the missing digit, checks the remaining cells by skipping them, and prints the completed grid. More generally, every completion must use one of the digits tried at each empty cell, so backtracking explores every permitted choice until it finds a completion or exhausts them.

If E cells are empty, a coarse upper bound is O(9^E) search work for this fixed board: each safety check examines a fixed number of cells. There are 81 input and answer cells and a recursive stack of at most about 81 cells, so space is constant for the nine-by-nine problem. Parameterized by E, the branching decisions use O(E) depth within that fixed traversal.

The program does not validate the starting clues. A fully filled but invalid board is accepted because fixed entries are skipped without checking their consistency. If no completion is found, the program prints nothing. It finds one completion and does not test whether it is unique.
