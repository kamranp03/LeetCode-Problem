# Problem 3234 - Count the Number of Substrings With Dominant Ones

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/
**Language:** C++

---

## Problem Statement

Given a binary string `s`, count the number of substrings where the number of `'1'`s is greater than or equal to the square of the number of `'0'`s. Formally, count substrings where `ones >= zeros * zeros`.

## Approach: Prefix Sum + Smart Jump Optimization

We precompute a prefix sum array `cum` where `cum[i]` = number of `'1'`s in `s[0..i]`. For each starting index `i` and ending index `j`, we compute `ones` and `zeros` for substring `s[i..j]`.

The key optimization: when `zeros^2 > ones`, we know we need to extend the window significantly. We jump `j` forward by `(zeros^2 - ones - 1)` positions to avoid checking all those invalid substrings individually. When `zeros^2 <= ones`, we count valid substrings and jump past the ones that are trivially also valid.

## Code Walkthrough (Step by Step)

1. **Build prefix sum `cum`:** `cum[i] = cum[i-1] + (s[i]=='1' ? 1 : 0)`.

2. **Nested loops with smart jumps:**
   - For each `i` (outer), for each `j >= i` (inner):
     - Compute `one = cum[j] - (i>0 ? cum[i-1] : 0)` and `zero = (j-i+1) - one`.
     - If `zero*zero > one`: need more `'1'`s, jump `j` by `extra - 1` where `extra = zero*zero - one`.
     - If `zero*zero == one`: count this substring (`res += 1`).
     - If `zero*zero < one`: count this AND all extensions. Adding one more `'1'` won't break dominance until `zeros` grows. Jump forward by `k = sqrt(one) - zero` positions.

3. **Return** `res`.

## Dry Run

**Example Input:** `s = "00011"`

- cum = [0, 0, 0, 1, 2]
- i=0, j=0: one=0, zero=1, 1>0 → jump
- i=0, j=2: one=0, zero=3, 9>0 → jump more
- i=3, j=3: one=1, zero=0, 0<=1 → res+=1+(more valid extensions)
- ... (detailed tracking of valid substrings with zeros squared check)

**Output:** A count of dominant substrings.

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n * sqrt(n)) | The jump optimization limits inner iterations to sqrt-bounded amount |
| **Space** | O(n) | Prefix sum array |
