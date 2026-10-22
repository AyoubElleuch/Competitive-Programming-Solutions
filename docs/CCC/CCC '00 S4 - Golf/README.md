# CCC '00 S4 - Golf

[Source code](../../../CCC/CCC%20'00%20S4%20-%20Golf.cpp) | [All CCC explanations](../README.md)

The recursive function asks how many strokes are needed for a remaining distance. It tries each club as the next shot, subtracts that club's distance, and solves the smaller remainder.

A remainder of zero needs no more strokes. A negative remainder is rejected with -1. For each successful recursive call, the function adds one stroke, collects the candidates, sorts them, and saves the smallest result in `dp`. An impossible remainder is also saved as -1, which avoids trying it again.

This works because any valid sequence has a first club. Trying every first club includes an optimal sequence, and the recursive result supplies its shortest continuation. For distance 10 with clubs 3 and 5, choosing 5 leaves 5, which needs one more stroke: two strokes in total.

Let D be the target distance and C the number of clubs. The expected time bound is O(D C² + D C log C): the function copies the club vector on every call, including calls that find a cached answer, and sorts candidates for each computed remainder. Hash lookups are expected O(1). Recursion can be O(D) deep with positive integer clubs, and copied vectors can use O(DC) space. Clubs must have positive lengths. A target of zero returns zero internally, but `main` prints defeat because it checks `ans > 0`.
