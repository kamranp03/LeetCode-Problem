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
    TreeNode* prev = NULL;
    TreeNode* fir = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        if (prev != NULL && root->val < prev->val) {
            if (!fir) {
                fir = prev;
            }
            sec = root;
        }
        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);

        int temp = fir->val;
        fir->val = sec->val;
        sec->val = temp;
    }
};