# Problem 182 - Duplicate Emails

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/duplicate-emails/
**Language:** SQL

---

## Problem Statement

Given a table `Person` with columns `id` and `email`, write a SQL query to report all duplicate email addresses (i.e., emails that appear more than once in the table). Return the result table in any order.

Table structure:
```
Person
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
```

## Approach: GROUP BY + HAVING COUNT

The key insight is to group all rows by the `email` column and then filter only those groups that contain more than one row. `GROUP BY email` collapses all rows with the same email into a single group, and `COUNT(email)` gives the number of rows in each group. The `HAVING` clause filters groups after aggregation (unlike `WHERE`, which filters individual rows before grouping).

## Code Walkthrough (Step by Step)

1. **`SELECT email AS Email`:** Select the email column, aliased as `Email` to match the expected output column name.

2. **`FROM Person`:** Query from the `Person` table.

3. **`GROUP BY email`:** Group all rows that share the same email address into a single group. Each unique email becomes one group.

4. **`HAVING COUNT(email) > 1`:** Keep only those groups where the count of rows (i.e., the number of times this email appears) is greater than 1 — meaning the email is a duplicate.

## Dry Run

**Example Input:**
```
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
```

- `GROUP BY email` creates two groups:
  - `a@b.com` → 2 rows (id 1 and id 3)
  - `c@d.com` → 1 row (id 2)
- `HAVING COUNT(email) > 1`:
  - `a@b.com`: 2 > 1 → included
  - `c@d.com`: 1 > 1 → excluded

**Output:**
```
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
```

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Grouping typically requires a sort or hash operation over n rows |
| **Space** | O(d) | d = number of distinct emails; the aggregation stores one entry per distinct email |
