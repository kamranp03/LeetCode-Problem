class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
        int n = skill.size();
        
        // The total sum must be divisible by the number of teams (n / 2)
        if (sum % (n / 2) != 0) {
            return -1;
        }
        
        long long targetTeamSkill = sum / (n / 2);
        sort(skill.begin(), skill.end());
        
        int i = 0;
        int j = n - 1;
        long long ans = 0;
        
        while (i < j) {
            // Check if every pair equals the required target skill sum
            if (skill[i] + skill[j] != targetTeamSkill) {
                return -1;
            }
            ans += (long long)skill[i] * skill[j];
            i++;
            j--;
        }
        
        return ans;
    }
};