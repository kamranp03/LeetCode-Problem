# Problem 79 - Word Search

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/word-search/
**Language:** C++

---

## Problem Statement

Given an `m x n` grid of characters (`board`) and a string `word`, return `true` if `word` exists in the grid. The word must be constructed from letters of sequentially adjacent cells (horizontally or vertically neighboring), and the same cell may not be used more than once.

## Approach: Backtracking DFS

The key insight is to try starting a DFS from every cell in the grid. When we visit a cell that matches the current character of the word, we temporarily mark it as `'#'` (visited) to prevent reuse in the same path, then recurse in all four directions. If we reach `idx == word.size()`, the entire word has been matched. After the recursive calls, we restore the cell to its original character (backtrack), allowing other paths to use it.

## Code Walkthrough (Step by Step)

1. **Outer loop — try every starting cell:** In `exist`, iterate over every `(i, j)` in the board. Call `dfs(board, word, i, j, 0)` where `0` is the index into `word` we're currently trying to match.

2. **Base case — full match:** At the start of `dfs`, if `idx == word.size()`, we've matched all characters successfully — return `true`.

3. **Boundary and character check:** If the cell is out of bounds, or the character at `board[row][col]` doesn't match `word[idx]`, return `false` immediately.

4. **Mark visited:** Save the current character in `temp`, then set `board[row][col] = '#'` to prevent revisiting this cell in the current path.

5. **Recurse in four directions:** Try moving down, up, right, and left — each advancing `idx` by 1. The result is ORed together; if any direction finds the word, propagate `true`.

6. **Backtrack:** Restore `board[row][col] = temp` so the cell is available for other starting paths.

## Dry Run

**Example Input:**
```
board = [['A','B','C','E'],
         ['S','F','C','S'],
         ['A','D','E','E']]
word = "ABCCED"
```

- Start DFS from (0,0) with idx=0 → matches 'A'.
- Mark (0,0)='#'. Move right to (0,1), idx=1 → matches 'B'.
- Mark (0,1)='#'. Move right to (0,2), idx=2 → matches 'C'.
- Mark (0,2)='#'. Move down to (1,2), idx=3 → matches 'C'.
- Mark (1,2)='#'. Move down to (2,2), idx=4 → matches 'E'.
- Mark (2,2)='#'. Move left to (2,1), idx=5 → matches 'D'.
- idx=6 == word.size() → return true!

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n * 4^L) | For each of m*n starting cells, DFS branches up to 4 directions for word length L |
| **Space** | O(L) | Recursion stack depth equals the word length L |
