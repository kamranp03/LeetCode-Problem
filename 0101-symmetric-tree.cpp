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
    bool isSym(TreeNode* p, TreeNode* q)
    {
          // both null
        
        if(p == NULL && q == NULL)
            return true;
        
        // one null
        if(p == NULL || q == NULL)
            return false;
        
        // values different
        if(p->val != q->val)
            return false;
        
        // check left and right subtree
        return isSym(p->left, q->right) &&
               isSym(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
         TreeNode* p=root->left;
         TreeNode* q=root->right;

         return isSym(p,q);
    }
};

