# Problem 1528 - Shuffle String

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/shuffle-string/
**Language:** C++

---

## Problem Statement

Given a string `s` and an integer array `indices` of the same length, shuffle the string so that character `s[i]` moves to position `indices[i]`. Return the shuffled string.

## Approach: Direct Index Mapping

The key insight is to create a result array of the same size and place each character directly at its target position. Instead of sorting or swapping, we use the index array as a direct mapping: `result[indices[i]] = s[i]`.

## Code Walkthrough (Step by Step)

1. **Get `n = indices.size()`** — the length of the string.
2. **Create `res`** — a `vector<char>` of size `n` to hold the output.
3. **Loop from `i = 0` to `n-1`:** Place `s[i]` at position `indices[i]` in `res`.
4. **Convert and return:** `string(res.begin(), res.end())` converts the char vector to a string.

## Dry Run

**Example Input:** `s = "codeleet"`, `indices = [4,5,6,7,0,2,1,3]`

| i | s[i] | indices[i] | res[indices[i]] |
|---|------|------------|-----------------|
| 0 | 'c' | 4 | res[4]='c' |
| 1 | 'o' | 5 | res[5]='o' |
| 2 | 'd' | 6 | res[6]='d' |
| 3 | 'e' | 7 | res[7]='e' |
| 4 | 'l' | 0 | res[0]='l' |
| 5 | 'e' | 2 | res[2]='e' |
| 6 | 'e' | 1 | res[1]='e' |
| 7 | 't' | 3 | res[3]='t' |

Result: `['l','e','e','t','c','o','d','e']` → **"leetcode"**

**Output:** `"leetcode"`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single pass to fill the result array |
| **Space** | O(n) | Result array of size n |
