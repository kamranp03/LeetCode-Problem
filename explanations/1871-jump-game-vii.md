# Problem 1871 - Jump Game VII

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/jump-game-vii/
**Language:** C++

---

## Problem Statement

Given a binary string `s` and integers `minJump` and `maxJump`, you start at index 0 (which is '0'). You can jump from index `i` to any index `j` where `i + minJump <= j <= i + maxJump` and `s[j] == '0'`. Return `true` if you can reach the last index `n-1`.

## Approach: BFS with Sliding Window (maxReach Optimization)

The key insight is to use BFS but avoid redundant exploration. The `maxReach` variable tracks how far we've already explored from previous queue entries. When processing a new index, we start searching from `max(ind + minJump, maxReach + 1)` — skipping positions already covered. This ensures each index is enqueued at most once, making the algorithm O(n) instead of O(n * (maxJump - minJump)).

## Code Walkthrough (Step by Step)

1. **Initialize:** Push index 0 into the queue. Set `maxReach = 0`.
2. **BFS loop:** Pop front index `ind`.
   - If `ind == n-1`, return `true` (reached last index).
   - Compute `st = max(ind + minJump, maxReach + 1)` and `end = min(ind + maxJump, n-1)`.
   - Iterate `i` from `st` to `end`: if `s[i] == '0'`, push `i` into queue.
   - Update `maxReach = end` so future BFS steps skip this range.
3. **Return `false`** if queue empties without reaching `n-1`.

## Dry Run

**Example Input:** `s = "011010"`, `minJump = 2`, `maxJump = 3`

- n=6, queue=[0], maxReach=0
- Pop 0: st=max(2,1)=2, end=min(3,5)=3; s[2]='1'(skip), s[3]='0'(push); maxReach=3
- Pop 3: st=max(5,4)=5, end=min(6,5)=5; s[5]='0'(push); maxReach=5
- Pop 5: ind==n-1=5 → return **true**

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each index is enqueued and processed at most once due to maxReach |
| **Space** | O(n) | Queue can hold up to n indices |
