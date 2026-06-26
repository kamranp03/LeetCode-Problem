# Problem 929 - Unique Email Addresses

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/unique-email-addresses/
**Language:** C++

---

## Problem Statement
Email addresses have two parts separated by '@'. In the local (left) part, dots '.' are ignored and everything after a '+' sign is ignored. The domain (right) part is kept as-is. Given a list of emails, return the count of unique normalized email addresses.

## Approach: String Processing + Hash Set

For each email, split it at '@' to get the local and domain parts. Process the local part by removing all '.' and stopping at '+'. Reconstruct the normalized email and insert it into an `unordered_set`. The set automatically handles deduplication. The answer is the size of the set.

## Code Walkthrough (Step by Step)

1. **Split at '@':** Scan characters until '@' to build `local`, then take the rest as `domain`.

2. **Filter local part:**
   - Iterate over each character `c` in `local`.
   - If `c == '+'`: stop processing (ignore the rest of local).
   - If `c == '.'`: skip (continue to next character).
   - Otherwise: append to `filteredLocal`.

3. **Build normalized email:** `filteredLocal + "@" + domain`.

4. **Insert** into the `unordered_set<string> unique`.

5. **Return** `unique.size()`.

## Dry Run

**Example Input:** `emails = ["test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"]`

| Raw Email                          | Local filtered | Domain        | Normalized                   |
|------------------------------------|----------------|---------------|------------------------------|
| test.email+alex@leetcode.com       | testemail      | leetcode.com  | testemail@leetcode.com       |
| test.e.mail+bob.cathy@leetcode.com | testemail      | leetcode.com  | testemail@leetcode.com       |
| testemail+david@lee.tcode.com      | testemail      | lee.tcode.com | testemail@lee.tcode.com      |

Set size = 2

**Output:** `2`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N * L) | N emails each of average length L processed linearly |
| **Space** | O(N * L) | Set stores up to N unique normalized email strings |
