# Problem 3433 - Count Mentions Per User

**Difficulty:** Medium
**LeetCode:** https://leetcode.com/problems/count-mentions-per-user/
**Language:** C++

---

## Problem Statement

Given a list of events (OFFLINE or MESSAGE) with timestamps and user data, simulate a messaging system. OFFLINE events take a user offline for 60 time units. MESSAGE events can mention ALL users, only HERE (currently online) users, or specific user IDs. Return the total mention count for each user.

## Approach: Event Simulation with Sorted Timeline

Sort events by timestamp (OFFLINE before MESSAGE at the same time, because going offline must be processed before a simultaneous message). Use a `map<time, users>` to track when each user comes back online. Process events chronologically, restoring users to online status as we reach their return time.

## Code Walkthrough (Step by Step)

1. **Sort events** by timestamp; at equal timestamps, OFFLINE events come first so users are taken offline before any simultaneous messages are processed.
2. **Initialize** `mentions` array (all zeros) and `online` array (all true).
3. **For each event,** first restore all users whose return time has been reached (from `backOnline` map).
4. **If OFFLINE:** mark user offline, schedule return at `time + 60` in `backOnline`.
5. **If MESSAGE with "ALL":** increment all users.
6. **If MESSAGE with "HERE":** increment only currently online users.
7. **If MESSAGE with specific IDs:** parse the "id{n}" tokens and increment those users.

## Dry Run

**Example Input:** `numberOfUsers = 2`, events = `[["OFFLINE","1","0"], ["MESSAGE","2","HERE"]]`

- Sort: OFFLINE at t=1, MESSAGE at t=2.
- Process OFFLINE t=1, user 0: `online[0]=false`, `backOnline[61]=[0]`.
- Process MESSAGE t=2, "HERE": user 0 is offline, user 1 is online → `mentions[1]++` → [0,1].

**Output:** `[0, 1]`

## Complexity Analysis

| | Complexity | Reason |
|--|--|--|
| **Time** | O(E log E + E * U) | E events sorted; "ALL"/"HERE" messages scan all U users |
| **Space** | O(U + E) | Online status array + backOnline map |
