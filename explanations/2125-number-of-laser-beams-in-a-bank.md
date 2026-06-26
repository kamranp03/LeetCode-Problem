# Problem 2125 - Number of Laser Beams in a Bank

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
**Language:** C++

---

## Problem Statement
A bank has security devices placed in rows. A laser beam can be formed between any device in row `i` and any device in row `j` if there is no device in any row between them. Given a binary matrix `bank` (where `'1'` represents a device), return the total number of laser beams.

## Approach: Row-by-Row Count with Multiplication

The key insight is that lasers form between consecutive non-empty rows only. If row `i` has `p` devices and the next non-empty row has `q` devices, they contribute `p * q` beams. Rows with zero devices are skipped entirely (they don't block beams). We maintain the previous non-empty row's device count and multiply with each new non-empty row's count.

## Code Walkthrough (Step by Step)

1. **Initialize `prev = 0`** (device count of the previous non-empty row) and `result = 0`.
2. **Loop over each row string** in `bank`:
   - Count `curr` = number of `'1'` characters in the current row.
   - If `curr == 0`: skip this row (it doesn't contribute beams or block them).
   - If `prev > 0`: add `prev * curr` to `result` (all pairs between the two non-empty rows form beams).
   - Update `prev = curr`.
3. **Return `result`**.

## Dry Run

**Example Input:**
```
bank = ["011001",
        "000000",
        "010100",
        "001000"]
```

| Row | curr (count of '1') | prev | result |
|-----|---------------------|------|--------|
| 0   | 3                   | 0    | 0      |
| 1   | 0 (skip)            | 3    | 0      |
| 2   | 2                   | 3    | 3*2=6  |
| 3   | 1                   | 2    | 6+2*1=8|

**Output:** `8`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * n) | Count '1's in each row — O(n) per row, m rows total |
| **Space** | O(1) | Only two scalar variables maintained |
