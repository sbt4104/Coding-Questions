/*
Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’.

Write a function to return an array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. It is given that none of the intervals have the same start point.
*/


/*
Solution: 
Maintain 2 heaps, maxendheap, maxStartHeap, so that we traverse from max end to min end and search for next max start consecutively
pick the top element from maxendheap, remove top from min heap and keep searching, after we find the next min start, mark it and push it back to min heap 
do this while maxheap is not empty
*/