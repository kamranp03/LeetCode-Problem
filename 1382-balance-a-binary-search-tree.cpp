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
   // Inorder traversal to store elements of the
// tree in sorted order
void storeInorder(TreeNode* root, vector<int>& nodes) {
    if (root == nullptr) 
        return;

    // Traverse the left subtree
    storeInorder(root->left, nodes);

    // Store the node data
    nodes.push_back(root->val);

    // Traverse the right subtree
    storeInorder(root->right, nodes);
}

// Function to build a balanced BST from a sorted array
TreeNode* buildBalancedTree(vector<int>& nodes, int start, int end) {
    
    // Base case
    if (start > end) 
        return nullptr;

    // Get the middle element and make it the root
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);

    // Recursively build the left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to balance a BST
TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;

    // Store the nodes in sorted order
    storeInorder(root, nodes);

    // Build the balanced tree from the sorted nodes
    return buildBalancedTree(nodes, 0, nodes.size() - 1);
}
};