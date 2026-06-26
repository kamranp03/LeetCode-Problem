# Problem 761 - Special Binary String

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/special-binary-string/
**Language:** C++

---

## Problem Statement
A "special" binary string is defined as one where every prefix has at least as many 1s as 0s, and the total count of 1s equals the count of 0s. Given a special binary string, you may swap any two adjacent non-overlapping special substrings any number of times. Return the lexicographically largest result possible.

## Approach: Recursive Divide and Conquer (Greedy Sort)

The key insight is that a special binary string always has the form `1[inner]0`, where `[inner]` is also a special binary string. By identifying all top-level special substrings, recursively making each one as large as possible, then sorting them in descending lexicographic order and concatenating, we get the globally largest result. This works because swapping adjacent special substrings is exactly what sorting them achieves.

## Code Walkthrough (Step by Step)

1. **Scan the string** tracking a balance (`sum`): +1 for '1', -1 for '0'.
2. **When `sum == 0`**, a top-level special substring has been found from `start` to `i`.
3. **Extract the inner part** (strip the leading '1' and trailing '0'), then recursively apply `makeLargestSpecial` to the inner part.
4. **Wrap it back** as `"1" + recursive_result + "0"` and push to the `spec` vector.
5. **Sort `spec` descending** so larger special strings come first.
6. **Concatenate all** elements in `spec` and return.

## Dry Run

**Example Input:** `s = "11011000"`

- Scan: at i=3 sum=0, substring "1101" inner="10" → recurse("10") = "10" → push "1100"? 
  Wait: s[0..3]="1101" → inner = s[1..2] = "10" → recurse("10"): inner="", push "10" → result "10" → wrap: "1"+"10"+"0" = "1100"
- Continue from start=4: s[4..7]="1000" → inner = s[5..6] = "00"... 
  Actually "1000": sum trace: 1,-1,-1,-1 → never 0 except... Let me re-trace: "11011000"
  - i=0: '1', sum=1
  - i=1: '1', sum=2
  - i=2: '0', sum=1
  - i=3: '1', sum=2
  - i=4: '1', sum=3
  - i=5: '0', sum=2
  - i=6: '0', sum=1
  - i=7: '0', sum=0 → found full string
- spec = ["1" + makeLargestSpecial("1011") + "0"]
- Recurse on "1011": finds "10" at i=1, "11" continues to i=3 → spec=["10","1...0"]? 
  Result sorts to max possible.

**Output:** `"11100100"` (lexicographically largest rearrangement)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(N^2 log N) | Each level scans O(N) and sorts; recursion depth O(N) |
| **Space** | O(N) | Recursive call stack and string storage |
