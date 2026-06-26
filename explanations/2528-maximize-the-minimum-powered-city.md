# Problem 2528 - Maximize the Minimum Powered City

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/maximize-the-minimum-powered-city/
**Language:** C++

---

## Problem Statement
You have `n` cities in a row and `n` power stations. Station `i` powers all cities within distance `r` (i.e., cities `[i-r, i+r]`). You can add exactly `k` more power stations anywhere. Maximize the minimum power any city receives, and return that minimum.

## Approach: Binary Search on Answer + Greedy Verification with Difference Array

The key insight is that the answer (minimum power) has a monotonic property: if a minimum of `mid` is achievable, any smaller minimum is also achievable. So binary search on the answer. For each candidate minimum `mid`, greedily verify: scan cities left to right, and whenever a city's current power drops below `mid`, place the needed stations as far right as possible (at position `i + r`) to cover the maximum future range.

## Code Walkthrough (Step by Step)

1. **Compute initial power** of each city using a difference array `diff[]`:
   - For each station `i` with value `station[i]`, add it to `diff[max(0, i-r)]` and subtract from `diff[i+r+1]` (if in bounds). Then prefix-sum `diff` to get actual power per city.
2. **Binary search** over `[left, right]` where `left = min(station)`, `right = total_sum + k`:
   - Call `check(mid, r, diff, k, n)`.
3. **`check(mid, r, diff, k, n)`**:
   - Copy `diff` to `temp`, compute prefix sums as `cumSum`.
   - For each city `i`: if `cumSum < mid`, we need `need = mid - cumSum` more power.
     - If `need > k` remaining: return false.
     - Otherwise deduct `need` from `k`, add `need` to `cumSum`, and subtract `need` from `temp[i + 2*r + 1]` (the effect of placing at `i+r` wears off after `i+2r`).
   - Return true if all cities can be powered.
4. **Return `result`** — the largest achievable minimum.

## Dry Run

**Example Input:** `station = [1,2,4,5,0], r=1, k=2`

Initial diff (each station covers [i-r, i+r]):
- Station[0]=1 covers [0,1]: diff[0]+=1, diff[2]-=1
- Station[1]=2 covers [0,2]: diff[0]+=2, diff[3]-=2
- Station[2]=4 covers [1,3]: diff[1]+=4, diff[4]-=4
- Station[3]=5 covers [2,4]: diff[2]+=5, diff[5]-=5
- Station[4]=0: no contribution

Prefix sums → power = [3, 7, 10, 9, 5]

Binary search: left=0, right=(1+2+4+5+0)+2=14
- mid=7: check if min ≥ 7 using 2 extra stations → feasible? City 0 has 3 < 7, need 4, but k=2 → false.
- ... eventually converges to ans=5.

**Output:** `5`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * log(sum+k)) | Binary search iterations × linear check pass |
| **Space** | O(n) | Difference array copy for each check |
