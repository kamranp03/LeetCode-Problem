# Problem 496 - Next Greater Element I

**Difficulty:** Easy
**LeetCode:** https://leetcode.com/problems/next-greater-element-i/
**Language:** C++

---

## Problem Statement
Given two arrays `nums1` and `nums2` where `nums1` is a subset of `nums2`, for each element in `nums1` find the next greater element in `nums2`. The next greater element of value `x` in `nums2` is the first element to the right of `x` that is strictly greater. If no such element exists, return -1 for that position.

## Approach: Monotonic Stack + Hash Map (Pre-compute)

The key insight is to pre-process `nums2` using a monotonic (decreasing) stack. We traverse `nums2` from right to left. For each element, we pop elements from the stack that are not greater (they can never be a "next greater" for the current element). The top of the stack after popping is the next greater element. We store the result in a hash map for O(1) lookup when answering queries for `nums1`.

## Code Walkthrough (Step by Step)

1. **Initialize** a hash map `m` and an empty stack `st`.

2. **Traverse `nums2` right to left** (index `i` from `nums2.size()-1` to 0):
   - **Pop** elements from stack while `st.top() <= nums2[i]` (they cannot be the next greater for nums2[i]).
   - **Assign:** If stack is empty, `m[nums2[i]] = -1`. Otherwise, `m[nums2[i]] = st.top()` (the next greater element).
   - **Push** `nums2[i]` onto the stack.

3. **Answer queries for `nums1`:** For each element in `nums1`, look up its next greater element in `m` and add to `ans`.

4. **Return `ans`.**

## Dry Run

**Example Input:** `nums1 = [4,1,2]`, `nums2 = [1,3,4,2]`

Traverse nums2 right to left:

| i | nums2[i] | Stack before pop | Pop | Stack after | m[nums2[i]] |
|---|----------|-----------------|-----|-------------|-------------|
| 3 | 2 | [] | — | [2] | m[2]=-1 |
| 2 | 4 | [2] | pop 2 | [] | m[4]=-1 |
| 1 | 3 | [] | — | [3] | m[3]=-1; push 3→wait: stack empty after popping? No: push 4 first. Let me redo: at i=2, stack=[2], pop 2 (2<=4), stack empty → m[4]=-1, push 4→[4]. i=1: stack=[4], 4>3 → m[3]=4, push 3→[4,3]. i=0: stack=[4,3], 3<=1? No. 3>1 → m[1]=3. |

Final map: m={2:-1, 4:-1, 3:4, 1:3}

Query nums1=[4,1,2]: ans=[m[4], m[1], m[2]] = [-1, 3, -1]

**Output:** `[-1, 3, -1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m + n) | Each element in nums2 is pushed/popped at most once; nums1 lookup is O(1) per element |
| **Space** | O(n) | Stack and hash map both store at most n elements from nums2 |
