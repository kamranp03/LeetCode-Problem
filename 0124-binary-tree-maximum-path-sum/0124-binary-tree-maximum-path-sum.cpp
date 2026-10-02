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
    int maxSum;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        // case 1 l+r+ root
        int full_path_ans = l + r + root->val;

        // case 2 max(l,r)+ root->val
        int only_one_side = max(l, r) + root->val;

        // case 3 only root
        int only_root = root->val;

        maxSum = max({maxSum, full_path_ans, only_one_side, only_root});

        // important part -> only return case 2 or 3

        return max(only_one_side, only_root);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);
        return maxSum;
    }
};