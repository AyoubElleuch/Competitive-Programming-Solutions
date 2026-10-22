# CCC '14 S3 - The Geneva Confection

[Source code](../../../CCC/CCC%20'14%20S3%20-%20The%20Geneva%20Confection.cpp) | [All CCC explanations](../README.md)

The solution simulates the incoming cars and the branch track. It reverses the input vector so the next car from the mountain is at `tmp[0]`. The vector `reserve` acts as a stack: cars enter and leave at its back.

`current` is the next car number needed at the lake, beginning at 1. If the incoming front equals current, the program sends it directly to the lake. Otherwise, it pops the branch top if that is the needed number. If neither is available, it puts the incoming car on the branch.

Once no incoming cars remain, the branch must release cars in order. A wrong number at its top blocks the required car, so the result is `N`; emptying both vectors gives `Y`. For an input whose processing order is `[3, 1, 2]`, the program parks 3, sends 1 and 2, then pops 3.

Each car is transferred a bounded number of times, but removing `tmp[0]` uses `erase(begin())` and shifts the remaining vector. That makes this implementation O(N²) time per test case, with O(N) space. Using an index for the incoming sequence would avoid those shifts. The simulation assumes car labels form a permutation of 1 through N.
