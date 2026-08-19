class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue < pair<int, int>> pq;
        int n = score.size();
        if (n == 1)
            return {"Gold Medal"};

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        vector<string> res(n, "");

        if (n == 2) {
            pair<int, int> p = pq.top();
            pq.pop();

            res[p.second] = "Gold Medal";

            p = pq.top();
            pq.pop();
            res[p.second] = "Silver Medal";
        }

        if (n >= 3) {
            pair<int, int> p = pq.top();
            pq.pop();

            res[p.second] = "Gold Medal";

            p = pq.top();
            pq.pop();
            res[p.second] = "Silver Medal";

            p = pq.top();
            pq.pop();
            res[p.second] = "Bronze Medal";
        }

        int i = 4;

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            res[p.second] = to_string(i);
            i++;
        }
        return res;
    }
};