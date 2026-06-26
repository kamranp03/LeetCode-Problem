# Problem 2054 - Two Best Non-Overlapping Events

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/two-best-non-overlapping-events/
**Language:** C++

---

## Problem Statement
You are given a list of events, each with a start time, end time, and value. You can attend at most two non-overlapping events (events cannot share any time). Return the maximum sum of values you can achieve by attending at most two events.

## Approach: Sort + Min-Heap (Greedy Sweep)

The key insight is to sort events by start time and use a min-heap ordered by end time to efficiently track all events that have already finished when we're considering the current event. We maintain `bestSoFar` — the best value among all finished events. For each event, we pop all finished events from the heap (updating `bestSoFar`), then consider: take just this event, or combine it with the best previously finished event.

## Code Walkthrough (Step by Step)

1. **Sort `events`** by start time.
2. **Initialize** a min-heap `pq` keyed by end time, `bestSoFar = 0`, `ans = 0`.
3. **For each event** `(start, end, value)`:
   - **Pop from heap**: While `pq.top().first < start`, pop the event and update `bestSoFar = max(bestSoFar, popped.second)`. These events have ended before our current event starts.
   - **Update `ans`**: `ans = max(ans, bestSoFar + value)` (combine best finished event with current).
   - Also `ans = max(ans, value)` (take only current event).
   - **Push current event** `{end, value}` onto the heap.
4. **Return `ans`**.

## Dry Run

**Example Input:** `events = [[1,3,2],[4,5,2],[2,4,3]]`

After sort by start: `[[1,3,2],[2,4,3],[4,5,2]]`

| Event     | Pop from heap       | bestSoFar | ans           | Push           |
|-----------|---------------------|-----------|---------------|----------------|
| [1,3,2]   | heap empty          | 0         | max(0,0+2)=2  | {3,2}          |
| [2,4,3]   | top={3,2}, 3<2? No  | 0         | max(2,0+3)=3  | {4,3},{3,2}    |
| [4,5,2]   | top={3,2}, 3<4? Yes → bestSoFar=2; top={4,3}, 4<4? No | 2 | max(3,2+2)=4 | {5,2}         |

**Output:** `4` (attend event [1,3,2] value=2 and [4,5,2] value=2)

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(n log n) | Sorting O(n log n) + each event pushed/popped once O(n log n) |
| **Space** | O(n) | Min-heap stores at most n events |
