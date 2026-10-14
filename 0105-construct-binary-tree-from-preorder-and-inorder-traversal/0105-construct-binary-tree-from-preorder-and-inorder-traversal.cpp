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
    // find idx in inorder
    int find(vector<int>& inorder, int left, int right, int ele)
    {
        for(int i=left;i<=right;i++)
        {
            if(inorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& pre, int left, int right)
    {
        // base case
        if(left>right) return NULL;

        // create roor
        TreeNode* root= new TreeNode(preorder[pre]);
        
        // find idx of current element in inorder
        int ino= find(inorder, left,right, preorder[pre]);
        pre++; 

        // left element must be which is left of side that element
        root->left= helper( preorder, inorder, pre, left, ino-1);
        // rigjht lement must be which is right side of that element
        root->right= helper( preorder, inorder, pre, ino+1, right);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // use inorder to generate tree using pre order
        int preIdx=0; // pre order idx
        
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};