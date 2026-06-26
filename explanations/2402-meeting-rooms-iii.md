# Problem 2402 - Meeting Rooms III

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/meeting-rooms-iii/
**Language:** C++

---

## Problem Statement
You have `n` meeting rooms numbered 0 to n-1. Meetings must be assigned to the lowest-numbered available room. If no room is free, the meeting is delayed until the earliest room becomes free (keeping the same duration). Return the room number that held the most meetings (break ties by returning the lower-numbered room).

## Approach: Two Priority Queues (Min-Heaps)

The key insight is to maintain two min-heaps: one for free rooms (sorted by room number) and one for busy rooms (sorted by end time, then room number). For each meeting (sorted by start time), free up all rooms whose end time has passed, then assign to the lowest free room. If no rooms are free, take the room that finishes earliest and delay the meeting.

## Code Walkthrough (Step by Step)

1. **Sort meetings** by start time.
2. **`available`**: min-heap of free room numbers. Initialize with all rooms 0..n-1.
3. **`busy`**: min-heap of `{endTime, roomNumber}` pairs.
4. **`count[n]`**: track how many meetings each room hosted.
5. **For each meeting** `(start, end, duration=end-start)`:
   - **Free rooms**: While `busy.top().first <= start`, move room from busy to available.
   - **Assign**:
     - If `available` is non-empty: take the lowest-numbered room, push `{end, room}` to busy.
     - Else: take the earliest-finishing room from `busy`, push `{freeTime + duration, room}` back.
   - Increment `count[room]`.
6. **Find the room with maximum count** (prefer lowest-numbered on tie).
7. **Return that room number**.

## Dry Run

**Example Input:** `n=2, meetings=[[0,10],[1,5],[2,7],[3,4]]`

Sort: [[0,10],[1,5],[2,7],[3,4]], available={0,1}, busy={}

| Meeting  | Free rooms | Available | Action               | busy                  | count        |
|----------|------------|-----------|----------------------|----------------------|--------------|
| [0,10]   | none       | {0,1}     | room 0, ends at 10   | {(10,0)}             | [1,0]        |
| [1,5]    | none       | {1}       | room 1, ends at 5    | {(5,1),(10,0)}       | [1,1]        |
| [2,7]    | 5>2: no    | {}        | earliest=(5,1), delay: 5+(7-2)=10, room 1 | {(10,0),(10,1)} | [1,2] |
| [3,4]    | none       | {}        | earliest=(10,0), delay: 10+(4-3)=11, room 0 | {(10,1),(11,0)} | [2,2] |

count = [2, 2] → tie → return room 0.

**Output:** `0`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(m log n) | m meetings × log n heap operations per meeting |
| **Space** | O(n + m) | Heaps store at most n and m entries respectively |
