# Problem 128 - Longest Consecutive Sequence

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/longest-consecutive-sequence/
**Language:** C++

---

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence. A consecutive sequence is a sequence of integers where each element is exactly 1 more than the previous (e.g., 1, 2, 3, 4). The algorithm must run in O(n) time.

## Approach: Hash Set - Start of Sequence Detection

The key insight is to insert all numbers into an unordered set for O(1) lookups, then only start counting a sequence from its genuine starting number. A number `x` is a sequence start if `x - 1` is NOT in the set. Once a start is found, count upward (`x+1`, `x+2`, ...) as long as consecutive numbers exist in the set. This ensures each sequence is counted exactly once, achieving O(n) overall.

## Code Walkthrough (Step by Step)

1. **Build hash set:** Insert all elements of `nums` into `unordered_set<int> st`. Handles duplicates automatically.

2. **Find sequence starts:** Iterate over every element `it` in `st`. Check if `st.find(it - 1) == st.end()`. If `it - 1` is NOT in the set, then `it` is the start of a new sequence.

3. **Count the sequence:** Starting from `x = it`, count how many consecutive numbers exist:
   - Initialize `cnt = 1`, `x = it`.
   - While `x + 1` is in the set: increment `x` and `cnt`.

4. **Update maximum:** `longest = max(longest, cnt)`.

5. **Return `longest`**.

## Dry Run

**Example Input:** `nums = [100, 4, 200, 1, 3, 2]`

- Set: `{100, 4, 200, 1, 3, 2}`
- Check 100: 99 not in set → start. Count: 100 → 101 not in set. cnt=1. longest=1.
- Check 4: 3 IS in set → not a start, skip.
- Check 200: 199 not in set → start. Count: 200 → 201 not in set. cnt=1. longest=1.
- Check 1: 0 not in set → start. Count: 1→2→3→4→5 not in set. cnt=4. longest=4.
- Check 3: 2 IS in set → not a start, skip.
- Check 2: 1 IS in set → not a start, skip.

**Output:** `4` (sequence: 1, 2, 3, 4)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Each element is inserted once and counted at most once (only from its sequence start) |
| **Space** | O(n) | Hash set stores all n elements |
