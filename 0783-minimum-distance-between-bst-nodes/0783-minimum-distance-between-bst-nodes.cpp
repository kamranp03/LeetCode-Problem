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
    TreeNode* prev;
    int minDiffInBST(TreeNode* root) {
        // base case
        if (root == NULL)
            return INT_MAX;

        int ans = INT_MAX;

        // left part min
        if (root->left) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        // root part ( we calculate the actual diff)
        if (prev != NULL)
            ans = min(ans, root->val - prev->val);
        prev = root;

        // right part min
        if (root->right) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};