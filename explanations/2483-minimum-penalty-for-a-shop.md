# Problem 2483 - Minimum Penalty for a Shop

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-penalty-for-a-shop/
**Language:** C++

---

## Problem Statement
A shop's customer log is a string of `'Y'` (customer came) and `'N'` (no customer). If the shop closes at hour `j`, the penalty is: number of `'Y'` entries after hour `j` (missed customers, shop was closed) plus number of `'N'` entries up to hour `j` (shop was open with no customer). Return the closing hour that minimizes the penalty.

## Approach: Prefix Scan with Running Penalty Adjustment

The key insight is to compute the initial penalty as if closing at hour 0 (all `'Y'`s are penalties). Then simulate opening the shop one hour at a time: each `'Y'` we pass reduces the penalty by 1 (that customer is now served), and each `'N'` we pass increases the penalty by 1 (open with no customer). Track the minimum penalty and its corresponding closing hour.

## Code Walkthrough (Step by Step)

1. **Initial penalty**: Count all `'Y'`s in the string (closing at hour 0 means every customer is a penalty).
2. **Set `minPenalty = penalty`** and `bestHour = 0`.
3. **Iterate `j` from 0 to n-1** (try closing at hour `j+1`):
   - If `customers[j] == 'Y'`: `penalty--` (serving this customer no longer penalizes).
   - Else (`'N'`): `penalty++` (being open with no customer adds a penalty).
   - If `penalty < minPenalty`: update `minPenalty = penalty`, `bestHour = j+1`.
4. **Return `bestHour`**.

## Dry Run

**Example Input:** `customers = "YYNY"`

Initial penalty = count('Y') = 3 (close at hour 0). minPenalty=3, bestHour=0.

| j | char | penalty adj | penalty | minPenalty | bestHour |
|---|------|-------------|---------|------------|----------|
| 0 | 'Y'  | -1          | 2       | 2          | 1        |
| 1 | 'Y'  | -1          | 1       | 1          | 2        |
| 2 | 'N'  | +1          | 2       | 1          | 2        |
| 3 | 'Y'  | -1          | 1       | 1          | 2        |

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Two linear passes: one to count 'Y's, one to scan and adjust |
| **Space** | O(1) | Only scalar variables; no extra data structures |
