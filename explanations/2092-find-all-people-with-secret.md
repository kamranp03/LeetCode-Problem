# Problem 2092 - Find All People With Secret

**Difficulty:** Hard
**LeetCode:** https://leetcode.com/problems/find-all-people-with-secret/
**Language:** C++

---

## Problem Statement
There are `n` people numbered 0 to n-1. Person 0 and person `firstPerson` know a secret at time 0. People hold meetings at various times and share the secret with everyone they meet (transitively, at the same timestamp). Return all people who know the secret after all meetings.

## Approach: Group Meetings by Time + BFS per Timestamp

The key insight is that all meetings at the same timestamp happen simultaneously — if any person in a connected group at time `t` knows the secret, everyone in that group learns it at time `t`. We group meetings by their timestamp, then for each timestamp run a BFS over the meeting graph to propagate the secret. Only people who already know the secret at that time can seed the BFS.

## Code Walkthrough (Step by Step)

1. **Group meetings by time**: Use a `map<int, vector<pair<int,int>>>` called `timeMeet`. Keys are sorted in ascending order automatically.
2. **Initialize `knows[n]`**: Boolean array. Set `knows[0] = true` and `knows[firstPerson] = true`.
3. **For each timestamp `t` and its meetings**:
   - Build an adjacency list `adj` from the meetings at time `t`.
   - Seed a BFS queue `que` with all people in these meetings who already `knows` the secret. Track added people with `already` set to avoid duplicates.
   - **BFS**: For each person dequeued, spread the secret to all their meeting partners who don't know it yet.
4. **Collect result**: Push all indices `i` where `knows[i] == true` into `res`.
5. **Return `res`**.

## Dry Run

**Example Input:** `n=6, meetings=[[1,2,5],[2,3,8],[1,5,10]], firstPerson=1`

Initial: knows = [T, T, F, F, F, F]

Time 5: meetings = [(1,2)]. adj: 1↔2. Queue: [1] (knows[1]=true). BFS: 1→2, knows[2]=true.
Time 8: meetings = [(2,3)]. adj: 2↔3. Queue: [2] (knows[2]=true). BFS: 2→3, knows[3]=true.
Time 10: meetings = [(1,5)]. adj: 1↔5. Queue: [1]. BFS: 1→5, knows[5]=true.

Result: [0, 1, 2, 3, 5]

**Output:** `[0, 1, 2, 3, 5]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(M log M + N + M) | M = meetings sorted by time; N = people; BFS total across all times is O(M+N) |
| **Space** | O(N + M) | knows array, adjacency list per timestamp, BFS queue |
