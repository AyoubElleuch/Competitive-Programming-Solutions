# IOI '09 P5 - Garage

[Source code](../../../IOI/IOI%20'09%20P5%20-%20Garage.cpp) | [All IOI explanations](../README.md)

The garage assigns an arriving car to the lowest-numbered free space. If every space is occupied, the car waits behind the other waiting cars. A parking charge is the car's weight multiplied by the space's rate.

For a positive event x, the code scans spaces from 1 upward. It marks the first free space occupied, remembers it in dp[x], and adds the charge. If the scan finds no space, it appends x to cars, the waiting list.

For a negative event -x, dp[x] gives the space to free. If anyone is waiting, the first waiting car takes that space immediately and pays its corresponding charge. The code erases the front of the waiting vector. In a valid event sequence there was no free space while that car was waiting, so the newly freed space is the one to use.

For two spaces with rates 3 and 2, and cars weighing 10, 20, and 30, process events 1, 2, 3, -1, -2, -3. Cars 1 and 2 pay 30 and 40; car 3 waits, then takes space 1 and pays 90. The printed total is 160.

Let S be the number of spaces and C the number of cars. Arrival scans cost O(CS). Removing the first vector element shifts the remaining waiting cars, which can add O(C²) work. With expected constant-time unordered_map operations, total time is O(CS + C²), and storage is O(S + C) conceptually; the space and weight arrays are fixed at 101 and 2001 entries.

The implementation assumes at most 100 spaces and 2000 cars, with valid arrival and departure events. Although the total is unsigned long long, each weight-times-rate product is evaluated as int before addition, so that product must fit in int. The waiting list is a vector, not a constant-time queue.
