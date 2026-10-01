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
    int mini = INT_MAX;
    void solve(TreeNode* root, int cnt) {
        if (root == NULL) {

            return;
        }
        if (root->left == NULL && root->right == NULL) {
            mini = min(mini, cnt + 1);
            return;
        }
        solve(root->left, cnt + 1);
        solve(root->right, cnt + 1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root, 0);
        return mini;
    }
};