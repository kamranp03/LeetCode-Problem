class Solution {
public:
    int n, target;

    bool solve(vector<int>& matchsticks, int i, vector<int>& sides) {

        // All matchsticks are used
        // If first 3 sides are correct, 4th is automatically correct
        if (i == n) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target;
        }

        // Try placing current matchstick in all 4 sides
        for (int j = 0; j < 4; j++) {

            // Skip if side exceeds target
            if (sides[j] + matchsticks[i] > target)
                continue;

            // Take current matchstick
            sides[j] += matchsticks[i];

            if (solve(matchsticks, i + 1, sides))
                return true;

            // Backtrack: remove matchstick and try another side
            sides[j] -= matchsticks[i];

            // Avoid trying other empty sides (duplicate choices)
            if (sides[j] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        n = matchsticks.size();

        if (n < 4) return false;

        // Calculate total length
        int sum = 0;
        for (int x : matchsticks)
            sum += x;

        // Four equal sides must be possible
        if (sum % 4 != 0)
            return false;

        target = sum / 4;

        // Place larger matchsticks first
        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target)
            return false;

        // Initially all four sides are empty
        vector<int> sides(4, 0);

        return solve(matchsticks, 0, sides);
    }
};

// class Solution {
// public:
//     unordered_map<int,int> mp;
//     int n;
//     vector<vector<int>> dp;
//     bool solve(vector<int>& matchsticks, int i, int target)
//     {
//         if(i>=n) return false;
//         if(target==0) return true;

//         if(dp[i][target] != -1)
//             return dp[i][target];
//         bool take= false;
//         if(target>= matchsticks[i] && mp[matchsticks[i]] >0)
//         {
//             mp[matchsticks[i]]--;
//             take= solve(matchsticks,i+1,target-matchsticks[i]);
//             mp[matchsticks[i]]++;
//         }
//         bool skip= solve(matchsticks,i+1, target);

//         return dp[i][target]= take || skip;
//     }
//     bool makesquare(vector<int>& matchsticks) {
//         n=matchsticks.size();
//         long long sum=0;

//         for(int i: matchsticks)
//         {
//             sum+=i;
//             mp[i]++;
//         }

//         if(sum%4!=0) return false;
//         int target= sum/4;
//         dp.assign(n+1,vector<int>(target+1,-1));

//         for(int i=0;i<4;i++)
//         {
//             if(!solve(matchsticks,0,target))
//                 return false;
//         }
//         return true;
//     }
// };