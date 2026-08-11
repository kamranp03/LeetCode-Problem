class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;

        int cnt = 0;
        int l = 0;
        while (i <= j) {
            if (people[j] + people[i] <= limit) {
                cnt++;
                j--;
                i++;

            } else {
                cnt++;
                j--;
            }
        }
        return cnt;
    }
};