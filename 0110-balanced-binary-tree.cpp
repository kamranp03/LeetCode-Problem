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
   
// Function to calculate the height of a tree
int height(TreeNode* node) {
  
    if (node == NULL)
        return 0;

    // Height = 1 + max of left height and right heights
    return 1 + max(height(node->left), height(node->right));
}

// Function to check if the binary tree with given root, is height-balanced
bool isBalanced(TreeNode* root) {

    if (root == NULL)
        return true;

    // Get the height of left and right sub trees
    int lHeight = height(root->left);
    int rHeight = height(root->right);
	
    if (abs(lHeight - rHeight) > 1)
        return false;

    // Recursively check the left and right subtrees
    return isBalanced(root->left) && isBalanced(root->right);
}
};