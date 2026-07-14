class Solution {
public:
    void solve(TreeNode* root, vector<int>& inor) {
        if (!root)
            return;

        solve(root->left, inor);
        inor.push_back(root->val);
        solve(root->right, inor);
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> inor;

        solve(root, inor);

        int st = 0;
        int end = inor.size() - 1;

        while (st < end) {
            int sum = inor[st] + inor[end];

            if (sum == k) {
                return true;
            } else if (sum > k) {
                end--;
            } else {
                st++;
            }
        }

        return false;
    }
};