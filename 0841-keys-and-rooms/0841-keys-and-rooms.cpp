class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[i] = true;
        for (auto& node : rooms[i]) {
            if (!vis[node]) {
                dfs(node, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        dfs(0, rooms, vis);

        for (bool b : vis) {
            if (!b)
                return false;
        }
        return true;
    }
};