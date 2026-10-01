/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    void solve(TreeNode* root, int sum, int targetSum, vector<int> curr) {
        if (root == NULL)
            return;

        curr.push_back(root->val);
        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == sum) {
                res.push_back(curr);
                curr.pop_back();
                return;
            }
            curr.pop_back();
            return;
        }

        solve(root->left, sum, targetSum, curr);
        solve(root->right, sum, targetSum, curr);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> curr;
        solve(root, sum, targetSum, curr);
        return res;
    }
};