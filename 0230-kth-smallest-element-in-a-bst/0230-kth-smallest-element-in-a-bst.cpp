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
    int order = 0;
    int kthSmallest(TreeNode* root, int k) {
        // base case
        if (root == NULL)
            return -1;

        // left tree
        if (root->left) {
            int left_ans = kthSmallest(root->left, k);
            if (left_ans != -1)
                return left_ans;
        }

        // root part (chcking root is kth or not)

        if (order + 1 == k)
            return root->val;
        order++;

        // right tree
        if (root->right) {
            int right_ans = kthSmallest(root->right, k);
            if (right_ans != -1)
                return right_ans;
        }

        return -1; // no ans
    }
};