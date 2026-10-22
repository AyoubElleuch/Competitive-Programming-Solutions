# CCC '13 S2 - Bridge Transport

[Source code](../../../CCC/CCC%20'13%20S2%20-%20Bridge%20Transport.cpp) | [All CCC explanations](../README.md)

The program simulates the bridge using a small vector named `railway` and a running weight `total`. That vector contains at most four cars, matching the bridge's capacity in car positions.

For the first four cars, it checks whether adding the next weight exceeds the limit. After that, it first removes the oldest car and subtracts its weight, then checks the incoming car. Each accepted car increments `count`. The simulation stops at the first car that would make the bridge too heavy, since later cars cannot pass it.

For a limit of 10 and weights `[2, 3, 2, 3, 4]`, the first four cars have total weight 10. Before the fifth arrives, the first weight of 2 leaves; adding 4 would produce 12, so the answer is four cars.

Reading and simulating N cars takes O(N) time. Erasing the vector's first element shifts at most three other entries, so this operation has constant cost here. The bridge simulation uses O(1) space, but the code stores all input weights in `cars`, making total space O(N). The running total and weight limit use `int` and assume the input sums fit that type.
