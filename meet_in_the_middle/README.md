# Bi-Directional Dijkstra

This algorithm is a more optimal implementation of the regular dijkstra's algorithm to find shortest path. 
It makes use of fact that the number of explorable nodes increases exponentially with each edge addition.
Thus we apply dijkstra's from both sides.

## Better Use

It is not very useful in graphs like those of the road networks
But it finds its use in web graphs like of FB ids, as it runs in near-polynomial time.

## Improvement

Since this is my first implementation of the meet-in-the-middle algorithm, it might be buggy.
If you find any bugs, please raise an issue.
If you feel it can be optimised further for the specific scenario, please raise an issue.
