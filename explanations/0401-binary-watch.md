# Problem 401 - Binary Watch

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/binary-watch/
**Language:** C++

---

## Problem Statement
A binary watch has 4 LEDs for hours (0-11) and 6 LEDs for minutes (0-59). Each LED represents a bit. Given `turnedOn` — the number of LEDs that are currently on — return all possible times the watch could display. Return the times as strings in the format `"H:MM"`.

## Approach: Brute Force Enumeration with Popcount

The key insight is that there are only 12 possible hour values (0-11) and 60 possible minute values (0-59), giving at most 720 combinations. For each (hour, minute) pair, count the total number of set bits using the built-in `__builtin_popcount` function. If the bit count equals `turnedOn`, this time is valid and gets added to the result.

## Code Walkthrough (Step by Step)

1. **Outer loop over hours:** `HH` from 0 to 11 (valid hour range for a 12-hour watch).

2. **Inner loop over minutes:** `MM` from 0 to 59.

3. **Popcount check:** `__builtin_popcount(HH) + __builtin_popcount(MM)` counts the total number of 1-bits across both values. If this equals `turnedOn`, the pair is a valid time.

4. **Format the string:** Hour is converted directly with `to_string(HH)`. Minutes need a leading zero if less than 10: `(MM < 10 ? "0" : "") + to_string(MM)`.

5. **Build result string:** Concatenate as `h + ":" + m` and push to result vector.

6. **Return the result** after all combinations are checked.

## Dry Run

**Example Input:** `turnedOn = 1`

Hours with 1 bit set (popcount=1): 1(0b0001), 2(0b0010), 4(0b0100), 8(0b1000)
Minutes with 1 bit set (popcount=1): 1, 2, 4, 8, 16, 32

Since we need total = 1:
- HH=0 (popcount=0), MM needs popcount=1 → MM=1,2,4,8,16,32 → "0:01","0:02","0:04","0:08","0:16","0:32"
- HH=1 (popcount=1), MM needs popcount=0 → MM=0 → "1:00"
- HH=2, MM=0 → "2:00"
- HH=4, MM=0 → "4:00"
- HH=8, MM=0 → "8:00"

**Output:** `["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Fixed number of iterations: 12 × 60 = 720 at most |
| **Space** | O(1) | Output size is bounded by 720 strings; no variable-size data structures |
