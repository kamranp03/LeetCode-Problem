/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans=NULL;
    void lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)   return;

        if(root==p || root==q)
        {
            ans=root;
            return;
        }

        if(root->val < p->val)
        {
            lca(root->right,p,q);
        }else if(root->val> q->val)
        {
            lca(root->left,p,q);
        }else{
            ans=root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val< q->val)
        {
            lca(root,p,q);
        }else{
            lca(root,q,p);
        }
        return ans;
    }
};