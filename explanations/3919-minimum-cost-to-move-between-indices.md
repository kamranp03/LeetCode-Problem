# Problem 3919 - Minimum Cost to Move Between Indices

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/minimum-cost-to-move-between-indices/
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and a list of queries `[l, r]`, for each query find the minimum cost to move from index `l` to index `r`. Movement cost depends on the direction and whether the neighbor is the "closest" to the current element. Moving toward the closest neighbor costs 1; otherwise it costs the absolute value difference. Return answers to all queries.

## Approach: Precompute Forward and Backward Cost Arrays

For each index `i`, determine its "closest" neighbor (the adjacent element with smaller absolute difference; tie breaks left). Then build:
- `forward[i]` = minimum cumulative cost to move left-to-right from index 0 to i.
- `backward[i]` = minimum cumulative cost to move right-to-left from index n-1 to i.

For a query `[l, r]`:
- If `l < r`: answer is `forward[r] - forward[l]`.
- If `l > r`: answer is `backward[r] - backward[l]`.

## Code Walkthrough (Step by Step)

1. **Compute `closest[i]`** for each i:
   - i=0: closest = 1 (only right neighbor).
   - i=n-1: closest = n-2 (only left neighbor).
   - Otherwise: choose left if `|nums[i]-nums[i-1]| <= |nums[i]-nums[i+1]|`, else right.
2. **Forward pass:** `forward[i] = forward[i-1] + (1 if closest[i-1]==i else |nums[i]-nums[i-1]|)`.
3. **Backward pass:** `backward[i] = backward[i+1] + (1 if closest[i+1]==i else |nums[i+1]-nums[i]|)`.
4. **Answer each query** using prefix differences.

## Dry Run

**Example Input:** `nums = [1, 3, 5, 2]`, `queries = [[0, 2], [2, 0]]`

- closest: [1, 0, 3, 2] (i=0→1; i=1: |1-3|=2>|3-5|=2 tie→left=0; i=2: |3-5|=2<|5-2|=3→left=1, wait |5-3|=2 vs |5-2|=3, left wins→closest[2]=1? Let me recheck: left=|5-3|=2, right=|5-2|=3. 2<=3 → closest[2]=1. i=3→2.)
- forward[0]=0. forward[1]=forward[0]+(closest[0]==1?1:|3-1|=2)=2. forward[2]=forward[1]+(closest[1]==2?1:|5-3|=2)=2+2=4. forward[3]=forward[2]+(closest[2]==3?1:|2-5|=3)=4+3=7.
- Query [0,2]: forward[2]-forward[0]=4-0=4.
- backward[3]=0. backward[2]=backward[3]+(closest[3]==2?1:|2-5|=3)=3. backward[1]=backward[2]+(closest[2]==1?1:|3-5|=2)=3+1=4. backward[0]=backward[1]+(closest[1]==0?1:|1-3|=2)=4+1=5.
- Query [2,0]: backward[0]-backward[2]=5-3=2.

**Output:** `[4, 2]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n + q) | O(n) precomputation, O(1) per query |
| **Space** | O(n) | forward, backward, and closest arrays |
