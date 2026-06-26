# Problem 0051 - N-Queens

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/n-queens/
**Language:** C++

---

## Problem Statement

Given an integer `n`, return all distinct solutions to the N-Queens puzzle. Place `n` queens on an `n×n` chessboard such that no two queens attack each other. Each solution is represented as a vector of strings, where `'Q'` marks a queen and `'.'` marks an empty cell.

## Approach: Backtracking (Row by Row)

The key insight is that exactly one queen must be placed in each row (since n queens on an n×n board with no two sharing a row). We recurse row by row, trying every column in the current row. Before placing a queen, we validate that it doesn't conflict with any already-placed queen via four checks: same row, same column, upper-left diagonal, upper-right diagonal. Only upward directions need checking since we haven't placed queens in lower rows yet.

## Code Walkthrough (Step by Step)

1. **`isSafe(board, n, row, col)`** — validates placement at `(row, col)`:
   - **Horizontal check:** scan all columns in `row` (shouldn't be needed since we place one per row, but serves as a guard).
   - **Vertical check:** scan all rows in `col` for a queen.
   - **Upper-left diagonal:** move `i--`, `j--` from `(row, col)` while both indices are valid.
   - **Upper-right diagonal:** move `i--`, `j++` from `(row, col)` while both indices are valid.
   - Return `true` only if no queen is found in any of these.

2. **`nQ(board, n, row, res)`** — recursive placer:
   - **Base case:** if `row == n`, all queens placed successfully — push board to `res`.
   - **Loop `i` from 0 to n-1:**
     - If `isSafe(board, n, row, i)`:
       - Place queen: `board[row][i] = 'Q'`.
       - Recurse to next row: `nQ(board, n, row+1, res)`.
       - Remove queen (backtrack): `board[row][i] = '.'`.

3. **`solveNQueens`** initializes an `n×n` board of `'.'` and calls `nQ` starting from `row = 0`.

## Dry Run

**Example Input:** `n = 4`

```
Row 0: try col 0 → blocked for row 1
Row 0: try col 1 → place Q at (0,1)
  Row 1: try col 3 → place Q at (1,3)
    Row 2: try col 0 → place Q at (2,0)
      Row 3: try col 2 → place Q at (3,2)
        row==4 → push [".Q..", "...Q", "Q...", "..Q."] ✓
Row 0: try col 2 → place Q at (0,2)
  Row 1: try col 0 → place Q at (1,0)
    Row 2: try col 3 → place Q at (2,3)
      Row 3: try col 1 → place Q at (3,1)
        row==4 → push ["..Q.", "Q...", "...Q", ".Q.."] ✓
```

**Output:** Two solutions for n=4.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n!) | At most n choices for row 0, n-1 for row 1, etc.; pruning reduces practical count |
| **Space** | O(n²) | Board is n×n; recursion depth is n |
