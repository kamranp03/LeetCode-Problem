# Problem 2141 - Maximum Running Time of N Computers

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/maximum-running-time-of-n-computers/
**Language:** C++

---

## Problem Statement
You have `n` computers and an array `batteries` where `batteries[i]` is the charge of the i-th battery. You can plug at most one battery into a computer at a time, but you can swap batteries freely between computers at any time. Return the maximum number of minutes you can run all `n` computers simultaneously.

## Approach: Binary Search on Answer

The key insight is that the answer has a monotonic property: if all `n` computers can run for `t` minutes, they can also run for any `t' < t` minutes. So binary search on the time `t`. For a candidate time `mid`, check if the total usable power across all batteries (each capped at `mid`, since no single battery can contribute more than `mid` minutes to one run) is at least `mid * n`.

## Code Walkthrough (Step by Step)

1. **Compute `sum`**: Total charge across all batteries.
2. **Binary search** over `[0, sum/n]`:
   - `left = 0`, `right = sum/n` (theoretical maximum per computer), `ans = 0`.
   - At each `mid`: compute `total = sum of min(b, mid) for each battery`.
   - If `total >= mid * n`: all n computers can run for `mid` minutes. Record `ans = mid`, search higher (`left = mid+1`).
   - Otherwise: search lower (`right = mid-1`).
3. **Return `ans`**.

**Why cap at `mid`?** A battery with charge 10 used in a computer that only runs for 5 minutes contributes at most 5 minutes, not 10 — the extra charge is unused during this particular run.

## Dry Run

**Example Input:** `n = 2, batteries = [3, 3, 3]`

sum = 9, right = 9/2 = 4

| mid | total = min(3,mid)*3 | mid*n | total>=mid*n? | ans |
|-----|----------------------|-------|---------------|-----|
| 2   | min(3,2)*3=6         | 4     | Yes           | 2   |
| 3   | min(3,3)*3=9         | 6     | Yes           | 3   |
| 4   | min(3,4)*3=9         | 8     | Yes           | 4   |

left=5 > right=4, stop.

**Output:** `4`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m * log(sum/n)) | m = number of batteries; binary search on answer |
| **Space** | O(1) | Only scalar variables; no extra arrays |
