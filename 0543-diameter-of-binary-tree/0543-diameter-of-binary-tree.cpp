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
 // Approach 1- O(n*n) 

// class Solution {
// public:
//     int height(TreeNode* root) {
//         if (root == NULL)
//             return 0;

//         int LH = height(root->left);
//         int RH = height(root->right);

//         return max(LH, RH) + 1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if (root == NULL)
//             return 0;

//         int leftDia = diameterOfBinaryTree(root->left);
//         int rightDia = diameterOfBinaryTree(root->right);
//         int dia = height(root->left) + height(root->right);

//         return max(dia, max(leftDia, rightDia));
//     }
// };

//Aproach 2 -> O(n) bcz we calculate dia at time of height no nmeed extra recursive call

class Solution {
public:
    int ans=0;
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int LH = height(root->left);
        int RH = height(root->right);

        ans=max(ans,LH+RH);// diameter
        return max(LH, RH) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }
};