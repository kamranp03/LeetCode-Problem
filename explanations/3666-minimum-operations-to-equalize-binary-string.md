# Problem 3666 - Minimum Operations to Equalize Binary String

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/
**Language:** C++

---

## Problem Statement

Given a binary string `s` of length `n` and an integer `k`, in one operation you can flip any `k` consecutive characters. Find the minimum number of operations to make all characters in `s` equal, or return -1 if it is impossible.

## Approach: BFS on Count of Zeros State

The key observation: flipping a window of `k` chars changes the count of 0s by some amount. We can model the state as the current number of 0s in the string. We want to reach state 0 (all 1s). Use BFS where each level is one operation, and transitions are all reachable counts of zeros after flipping any valid window (taking into account window position constraints).

Specifically, if current state has `cur` zeros:
- The reachable new zero-counts after one flip form a range `[l, r]`, where `l = cur + k - 2*min(cur, k)` and `r = cur + k - 2*max(k - (n - cur), 0)`.

## Code Walkthrough (Step by Step)

1. **Initialize** sets `ts[0]` and `ts[1]` containing all possible states by parity.
2. **Start BFS** from `cnt0` (current number of 0s in `s`), removing it from its parity set.
3. **Each BFS level** is one operation. For each state `cur`:
   - If `cur == 0`, return current answer (done).
   - Compute range `[l, r]` of reachable new states.
   - Add all states in `[l, r]` with correct parity from `ts[l%2]` to the BFS queue.
4. **Return -1** if BFS exhausts without reaching 0.

## Dry Run

**Example Input:** `s = "0110"`, `k = 2`

- cnt0 = 2. Start at state 2.
- ans=0: cur=2. l = 2+2-2*2=0, r = 2+2-2*0=4. Range [0,4]. Find 0 in ts[0]: push 0. ans=1? Actually cur=0 returns immediately in next iteration.
- Actually: process cur=2 → finds 0 in range [0,4]. Push 0 to queue. After processing queue, check cur=0 → return ans=1.

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | BFS with at most n states; set operations O(log n) |
| **Space** | O(n) | Two sets storing up to n+1 states |
