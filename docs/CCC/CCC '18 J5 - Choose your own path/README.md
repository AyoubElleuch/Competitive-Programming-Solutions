# CCC '18 J5 - Choose your own path

[Source code](../../../CCC/CCC%20'18%20J5%20-%20Choose%20your%20own%20path.cpp) | [All CCC explanations](../README.md)

The story is a directed graph: each page lists the pages it can lead to, and a page with no outgoing links is an ending. The program searches from page 1 to check reachability and find the shortest route to an ending.

Two vectors represent consecutive breadth-first layers. `added` marks pages when scheduled, and `visited` marks pages when processed, so a page is counted once even if several links lead to it. The search continues after finding an ending because it still needs to determine whether all pages are reachable.

`steps` starts at one to count the starting page. Before exploring another layer, it increases until an ending is discovered among the next pages. For `1 -> 2 -> 3` with page 3 an ending, it stops at three pages. The first output is `Y` when the number of visited pages equals n, otherwise `N`.

Traversal takes O(V + E) time. The fixed arrays and adjacency-vector headers reserve 10001 entries, with O(E) additional edge storage. Page labels must be at most 10000. An ending on page 1 is missed by the detection logic: for a one-page story, the code prints two instead of one. If no ending is reachable, `steps` keeps increasing until traversal ends and does not represent a valid ending distance.
