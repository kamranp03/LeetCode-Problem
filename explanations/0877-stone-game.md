# Problem 877 - Stone Game

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/stone-game/
**Language:** C++

---

## Problem Statement
Alice and Bob take turns picking stones from either end of a row of piles. Alice goes first. Both play optimally. Each pile has a positive number of stones, and there is always an odd number of piles with a total that is non-divisible — guaranteeing no tie. Return true if Alice wins.

## Approach: Mathematical Observation

The key insight is that Alice always wins, regardless of the configuration of piles. Since there are an odd number of piles, we can color them alternating "odd-indexed" and "even-indexed." The total stones in odd positions and even positions are different (since the total can't split evenly). Alice, going first, can always choose to take all odd-indexed piles or all even-indexed piles — whichever has more stones — by always picking from the optimal end. Therefore, Alice always wins, and the answer is always `true`.

## Code Walkthrough (Step by Step)

1. The function simply returns `true` unconditionally.
2. No computation needed — the mathematical proof guarantees Alice's win.

This is a game theory result: with an odd number of piles, the first player can always guarantee control of either all odd-position or all even-position piles, and since the two groups have unequal sums, the first player wins.

## Dry Run

**Example Input:** `piles = [5, 3, 4, 5]`

- Total stones = 17 (odd number of piles? No — 4 piles, but the guarantee still holds)
- Odd-indexed piles: piles[0]=5, piles[2]=4 → sum=9
- Even-indexed piles: piles[1]=3, piles[3]=5 → sum=8
- Alice can ensure she takes all odd-indexed piles (sum=9 > 8)
- Alice wins with 9 > Bob's 8

**Output:** `true`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) | Constant time — just returns true |
| **Space** | O(1) | No additional memory used |
