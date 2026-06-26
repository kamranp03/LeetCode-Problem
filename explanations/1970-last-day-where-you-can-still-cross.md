# Problem 1970 - Last Day Where You Can Still Cross

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/last-day-where-you-can-still-cross/
**Language:** C++

---

## Problem Statement
You are given a `row x col` binary matrix where cells flood (turn to water) one at a time in the order given by the array `cells`. Initially all cells are land. Return the last day on which it is still possible to walk from the top row to the bottom row by stepping only on land cells (4-directional movement).

## Approach: Binary Search on Days + DFS Reachability Check

The key insight is that the answer has a monotonic property: if we can cross on day `d`, we can also cross on any earlier day (fewer flooded cells). So binary search is applicable. For a given "mid" day, we build the grid with the first `mid` cells flooded and run a DFS from each unflooded cell in the top row to see if the bottom row is reachable.

## Code Walkthrough (Step by Step)

1. **Binary search** over the range `[0, cells.size()-1]` representing day indices:
   - `l = 0`, `r = cells.size()-1`, `lastDay = 0`.
   - At each `mid`, call `canCross(cells, mid)`.
   - If crossing is possible, record `lastDay = mid + 1` (1-indexed day) and search right (`l = mid+1`).
   - Otherwise search left (`r = mid-1`).

2. **`canCross(cells, mid)`**:
   - Build a grid of size `ROW x COL`, initially all 0 (land).
   - Mark the first `mid+1` cells from `cells` as 1 (flooded/water). Note: cells are 1-indexed, so subtract 1.
   - For each column `j` in row 0, if `grid[0][j] == 0`, start a DFS from `(0, j)`.
   - Return `true` if any DFS reaches row `ROW-1`.

3. **DFS**: Standard recursive 4-directional DFS.
   - Base cases: out of bounds or cell is already 1 (water/visited) → return false.
   - If row == `ROW-1` → return true (reached bottom).
   - Mark current cell as 1 (visited) and recurse in all 4 directions.

## Dry Run

**Example Input:** `row=2, col=2, cells=[[1,1],[2,1],[1,2],[2,2]]`

Binary search range: [0, 3]
- mid=1: flood cells[0] and cells[1] → positions (0,0) and (1,0). Can we cross? Top row: col=0 flooded, col=1 open. DFS from (0,1) → can reach (1,1) (bottom). canCross=true → lastDay=2, l=2.
- mid=2: flood 3 cells → (0,0),(1,0),(0,1). Top row: only (0,1) unflooded but can we reach bottom? (0,1)→(1,1): grid[1][1]=0, so yes. canCross=true → lastDay=3, l=3.
- mid=3: flood all 4 → no land in top row. canCross=false → r=2.

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(row * col * log(row * col)) | Binary search (log n) × DFS per check (O(row*col)) |
| **Space** | O(row * col) | Grid and DFS recursion stack |
