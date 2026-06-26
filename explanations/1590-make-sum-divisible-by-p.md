# Problem 1590 - Make Sum Divisible by P

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/make-sum-divisible-by-p/
**Language:** C++

---

## Problem Statement

Given an array of positive integers `nums` and a positive integer `p`, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by `p`. Return the length of the smallest subarray to remove, or -1 if it's impossible.

## Approach: Prefix Sum Modulo with Hash Map

The key insight is that the total sum mod p gives us the `need` — what we must remove. We look for the shortest subarray whose sum is congruent to `need` mod p. Using prefix sums modulo p and a hash map (similar to two-sum), we find the best match in one pass.

## Code Walkthrough (Step by Step)

1. **Compute `need = total % p`.** If 0, return 0 (already divisible).
2. **Initialize hash map `mp` with `mp[0] = -1`** (prefix sum 0 before the array starts).
3. **Iterate with running `prefix` sum modulo p:**
   - Compute `prefix = (prefix + nums[i]) % p`.
   - Compute `target = (prefix - need + p) % p` — the prefix value we're looking for to isolate a subarray with sum ≡ need (mod p).
   - If `target` exists in the map, update `ans = min(ans, i - mp[target])`.
   - Store `mp[prefix] = i`.
4. **Return `-1` if `ans == nums.size()`** (no valid subarray found), else return `ans`.

## Dry Run

**Example Input:** `nums = [3,1,4,2]`, `p = 6`

- total=10, need=10%6=4
- i=0: prefix=3, target=(3-4+6)%6=5 → not in map; mp[3]=0
- i=1: prefix=4, target=(4-4)%6=0 → mp[0]=-1 → len=1-(-1)=2; ans=2; mp[4]=1
- i=2: prefix=2, target=(2-4+6)%6=4 → mp[4]=1 → len=2-1=1; ans=1; mp[2]=2
- i=3: prefix=4, target=0 → mp[0]=-1 → len=3-(-1)=4; mp[4]=3
- Return **1**

**Output:** `1`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass with O(1) hash map operations |
| **Space** | O(n) | Hash map stores up to n prefix values |
