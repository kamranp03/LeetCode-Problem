# Problem 994 - Rotting Oranges

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/rotting-oranges/
**Language:** C++

---

## Problem Statement
Given an m×n grid where 0 = empty, 1 = fresh orange, 2 = rotten orange, every minute each fresh orange adjacent (4-directionally) to a rotten orange becomes rotten. Return the minimum number of minutes until no fresh orange remains, or -1 if it is impossible.

## Approach: Multi-Source BFS

Start BFS simultaneously from all initially rotten oranges (multi-source BFS). Each BFS level represents one minute of spreading. Track the time each orange was reached. After BFS completes, scan the grid for any fresh orange that was never visited — if found, return -1. Otherwise return the maximum time recorded.

## Code Walkthrough (Step by Step)

1. **Initialize:** Push all rotten oranges `(i, j)` into the queue with time=0. Mark them visited.

2. **BFS loop:** Process the queue:
   - Dequeue `(i, j, t)`. Update `ans = max(ans, t)`.
   - For each of the 4 neighbors: if in-bounds, unvisited, and fresh (value==1), push to queue with time `t+1` and mark visited.

3. **After BFS:** Scan the entire grid. If any cell has value 1 and was not visited (still fresh), return -1.

4. **Return `ans`** — the time when the last orange rotted.

## Dry Run

**Example Input:**
```
grid = [[2,1,1],
        [1,1,0],
        [0,1,1]]
```

- Initial rotten: (0,0) at t=0
- Minute 1: (0,1) and (1,0) rot → queued at t=1
- Minute 2: (0,2), (1,1) rot → queued at t=2
- Minute 3: (2,1) rots → t=3; (1,1) already visited
- Minute 4: (2,2) rots → t=4
- No fresh oranges left. ans=4

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(M * N) | Each cell enqueued and processed at most once |
| **Space** | O(M * N) | Queue can hold all cells; visited array same size |
