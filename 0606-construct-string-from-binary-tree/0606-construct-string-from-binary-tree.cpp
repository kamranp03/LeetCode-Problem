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
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return "";

        string res= to_string(root->val); //Root (L)(R)

        string left= tree2str(root->left);
        string right= tree2str(root->right);

        if(root->left==NULL && root->right==NULL)
            return res;

        if(root->left==NULL)
            return res+ "()"+"("+right+")";
        if(root->right==NULL)
            return res+ "("+ left+")";

        return res + "("+left+")"+"("+right+")";          
    }
};