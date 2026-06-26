# Problem 2147 - Number of Ways to Divide a Long Corridor

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
**Language:** C++

---

## Problem Statement
A long corridor contains seats (`'S'`) and plants (`'P'`). You must divide it into sections by placing dividers such that each section contains exactly 2 seats. Return the number of ways to place dividers modulo 10^9 + 7.

## Approach: Count Plants Between Consecutive Seat Pairs

The key insight is that the total number of seats must be even and non-zero, or the answer is 0. Each valid division places a divider somewhere between the 2nd seat of one pair and the 1st seat of the next pair. The number of plants between these two seats gives the number of valid divider positions for that gap (plants+1 choices: before the first plant, between any two plants, or after the last plant). Multiply all choices together.

## Code Walkthrough (Step by Step)

1. **Count total seats**: If odd or zero, return 0 immediately.
2. **Track `seatCount`**, `plantCount`, and a `started` flag.
3. **Single pass over corridor**:
   - On encountering `'S'`:
     - If `seatCount % 2 == 0` (completed a 2-seat block): set `started = true`, reset `plantCount = 0`.
     - Else if `started` (starting a new 2-seat block): multiply `ans` by `(plantCount + 1)` and reset `plantCount = 0`.
     - Increment `seatCount`.
   - On encountering `'P'`: if `started`, increment `plantCount`.
4. **Return `ans % M`**.

## Dry Run

**Example Input:** `corridor = "SSPPSPS"`

Seats at indices: 0, 1, 4, 6 → total 4 seats (even, ok).

Pass:
- i=0 'S': seatCount=1
- i=1 'S': seatCount=2, seatCount%2==0 → started=true, plantCount=0
- i=2 'P': started=true → plantCount=1
- i=3 'P': plantCount=2
- i=4 'S': seatCount=3, started & odd → ans *= (2+1)=3, plantCount=0
- i=5 'P': plantCount=1
- i=6 'S': seatCount=4, seatCount%2==0 → started=true (already), plantCount=0

ans = 1 * 3 = 3

**Output:** `3`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n) | Single linear pass through the corridor string |
| **Space** | O(1) | Only a few scalar counters and the modular answer |
