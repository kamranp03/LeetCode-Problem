/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    void solve(TreeNode* root)
    {
        // If no node, return
        if(root == NULL)
            return;

        // First visit greater values
        solve(root->right);

        // Add current value to sum
        sum += root->val;

        // Replace current value with total sum
        root->val = sum;

        // Then visit smaller values
        solve(root->left);
    }

    TreeNode* bstToGst(TreeNode* root)
    {
        // Reverse inorder: Right -> Root -> Left
        solve(root);

        return root;
    }
};

/*

BST:
smaller ← root → greater

Normal inorder:
Left → Root → Right

But we need GREATER values first:
Right → Root → Left

Keep a running sum:
sum += root->val
root->val = sum
*/