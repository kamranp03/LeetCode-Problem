# Problem 1578 - Minimum Time to Make Rope Colorful

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
**Language:** C++

---

## Problem Statement

Alice has a rope with `n` balloons, each with a color `colors[i]` and a removal time `neededTime[i]`. She wants no two consecutive balloons to have the same color. Return the minimum total time to remove balloons to achieve this.

## Approach: Greedy — Keep the Maximum in Each Consecutive Group

The key insight is that for any group of consecutive same-colored balloons, we must remove all but one (the most expensive to remove, so we keep it and remove the cheaper ones). We greedily accumulate the minimum costs: when we see a same-color as before, add `min(pre, neededTime[i])` to cost and keep `pre = max(pre, neededTime[i])`.

## Code Walkthrough (Step by Step)

1. **Initialize `time = 0`** and `pre = neededTime[0]` (track max time in current group).
2. **Iterate from `i = 1`:**
   - If `colors[i] == colors[i-1]` (same color group): Add `min(pre, neededTime[i])` to `time` (remove the cheaper balloon). Update `pre = max(pre, neededTime[i])` (keep the more expensive one).
   - If `colors[i] != colors[i-1]` (new color): Reset `pre = neededTime[i]` (start fresh group).
3. **Return `time`.**

## Dry Run

**Example Input:** `colors = "abaac"`, `neededTime = [1,2,3,4,5]`

- i=1: colors[1]='b' != 'a' → pre=2
- i=2: colors[2]='a' != 'b' → pre=3
- i=3: colors[3]='a' == 'a' → time += min(3,4)=3; pre=max(3,4)=4
- i=4: colors[4]='c' != 'a' → pre=5
- Total time = **3**

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass through colors and neededTime |
| **Space** | O(1) | Only `time` and `pre` variables |
