class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        // Sort by timestamp, OFFLINE before MESSAGE if same time
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if (a[1] != b[1]) 
                return stoi(a[1]) < stoi(b[1]);
            return a[0] == "OFFLINE";
        });

        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);

        // time -> users coming back online
        map<int, vector<int>> backOnline;

        for (auto &e : events) {
            int time = stoi(e[1]);

            // Bring back all users whose return time <= current time
            while (!backOnline.empty() && backOnline.begin()->first <= time) {
                for (int u : backOnline.begin()->second)
                    online[u] = true;
                backOnline.erase(backOnline.begin());
            }

            if (e[0] == "OFFLINE") {
                int id = stoi(e[2]);
                online[id] = false;
                backOnline[time + 60].push_back(id);
            } 
            else { // MESSAGE
                string msg = e[2];

                if (msg == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                } 
                else if (msg == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++)
                        if (online[i]) mentions[i]++;
                } 
                else {
                    stringstream ss(msg);
                    string token;
                    while (ss >> token) {
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};
