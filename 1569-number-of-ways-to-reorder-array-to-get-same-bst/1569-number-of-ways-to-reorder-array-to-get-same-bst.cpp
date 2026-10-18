class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    // optimize nCr formula
    vector<vector<ll>> pt;
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 1;

        // devide array in 2 parts left and right like subtree
        vector<int> left, right;

        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else if (nums[i] >= root)
                right.push_back(nums[i]);
        }

        // all time root is same only left and right tree will chenge so get ans from nboth
        ll x = solve(left);
        ll y = solve(right);
        // z= n C r
        ll z = pt[n - 1][left.size()]; // n-1 C left.size();

        // last and will be x* y *z , that ways we have for tree same bst
        return (((x * y) % MOD * z)) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        pt.resize(n + 1);

        // populating pascals triagle

        for (int i = 0; i <= n; i++) {
            pt[i] = vector<ll>(i + 1, 1);

            for (int j = 1; j < i; j++) {
                pt[i][j] = (pt[i - 1][j - 1] + pt[i - 1][j]) % MOD;
            }
        }
        return (solve(nums) - 1) % MOD;
    }
};