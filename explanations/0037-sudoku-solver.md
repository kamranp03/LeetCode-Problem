# Problem 0037 - Sudoku Solver

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/sudoku-solver/
**Language:** C++

---

## Problem Statement

Given a partially filled 9×9 Sudoku board (with `'.'` for empty cells), fill in the board such that each row, each column, and each of the nine 3×3 sub-boxes contains all digits from `'1'` to `'9'`. The input is guaranteed to have exactly one solution.

## Approach: Backtracking (Recursive Cell-by-Cell)

The key insight is to process cells one at a time (row by row, column by column) and try placing each digit `'1'`–`'9'` in each empty cell. Before placing, validate the digit using three checks: no duplicate in the same row, column, or 3×3 box. If placing a digit leads to a dead end deeper in the recursion, we erase it (backtrack) and try the next digit. The recursion terminates successfully when we've filled past the last cell (row 9).

## Code Walkthrough (Step by Step)

1. **`issafe(board, row, col, dig)`** — validates that `dig` can be placed at `(row, col)`:
   - Check all 9 cells in the same row for `dig`.
   - Check all 9 cells in the same column for `dig`.
   - Find the top-left corner of the 3×3 box: `sr = (row/3)*3`, `sc = (col/3)*3`. Check all 9 cells in that box.
   - Return `true` only if none of the checks found `dig`.

2. **`sudo(board, row, col)`** — recursive solver:
   - Compute next cell: `newcol = col+1`; if `newcol == 9`, wrap to `newrow = row+1, newcol = 0`.
   - **Base case:** if `row == 9`, the entire board is filled — return `true`.
   - If current cell is **pre-filled** (`!= '.'`): skip it by calling `sudo(board, newrow, newcol)`.
   - If current cell is **empty**: try each digit `'1'`–`'9'`:
     - If `issafe`, place the digit.
     - Recurse: if recursion returns `true`, propagate `true`.
     - Else: erase the digit (set back to `'.'`) and try next.
   - If no digit works, return `false` (trigger backtrack in caller).

3. **`solveSudoku`** just calls `sudo(board, 0, 0)`.

## Dry Run

**Simplified example:** Board with one empty cell at (0,0), row 0 has digits 2–9, column 0 has digits 2–9, box has digits 2–9.

- Try '1' at (0,0): `issafe` checks row (no '1'), column (no '1'), box (no '1') → safe.
- Place '1', recurse to next cell.
- If rest of board already filled → `row == 9` → return `true`.
- Board solved.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(9^m) | m = number of empty cells; each can try 9 digits |
| **Space** | O(m) | Recursion depth equals number of empty cells |
