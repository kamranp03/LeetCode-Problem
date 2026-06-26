# Problem 2043 - Simple Bank System

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/simple-bank-system/
**Language:** C++

---

## Problem Statement
Implement a bank system with `n` accounts. Each account has a balance. Support three operations: `transfer(account1, account2, money)`, `deposit(account, money)`, and `withdraw(account, money)`. Each operation should return `true` on success and `false` on invalid input (non-existent account or insufficient funds).

## Approach: Array-Based Account Storage with Validation

The key insight is to store all balances in a 1-indexed vector and validate account numbers before performing any operation. All operations are O(1) since we access by index. The 1-to-n validation guard handles out-of-range accounts uniformly.

## Code Walkthrough (Step by Step)

1. **Constructor**: Store `balance` vector as `bal` and store `n = balance.size()`.
2. **`isValid(account)`**: Returns `true` if `1 <= account <= n`. All three operations use this guard.
3. **`transfer(account1, account2, money)`**:
   - Validate both accounts with `isValid`.
   - Check that `bal[account1-1] >= money` (sufficient funds).
   - Subtract `money` from account1, add to account2, return `true`.
4. **`deposit(account, money)`**:
   - Validate account.
   - Add `money` to `bal[account-1]`, return `true`.
5. **`withdraw(account, money)`**:
   - Validate account.
   - Check sufficient funds.
   - Subtract `money`, return `true`.

## Dry Run

**Example:**
```
Bank bank([10, 100, 20, 50, 30]);
bank.transfer(5, 1, 20)  → bal[4]=10, bal[0]=30 → true
bank.deposit(5, 20)      → bal[4]=30 → true
bank.withdraw(10, 50)    → isValid(10)? No (n=5) → false
bank.transfer(5, 1, 15)  → bal[4]=15, bal[0]=45 → true
bank.transfer(3, 4, 22)  → bal[2]=20 < 22 → false
bank.deposit(2, 50)      → bal[1]=150 → true
bank.withdraw(4, 100)    → bal[3]=50 < 100 → false
```

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(1) per operation | Direct index access into the balance array |
| **Space** | O(n) | Storage for n account balances |
