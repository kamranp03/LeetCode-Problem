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
public:          // <node  , parent>
    unordered_map<TreeNode* , TreeNode*> mp;
    TreeNode* st;
    // traverse for finding parents and start node address
    void inorder(TreeNode* root,int start)
    {
        if(root==NULL) return;

        // start node address
        if(root->val== start) 
            st= root;
        if(root->left != NULL)
            mp[root->left]= root;
        inorder(root->left, start);

        
        if(root->right != NULL)
            mp[root->right]= root;
        inorder(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        
        inorder(root,start);
        unordered_set<int> vis;// for mark visited (all have distinc value)
        queue<pair<TreeNode*,int>> q; 
        int ans=0;
        q.push({st,0});
        vis.insert(start);

        while(!q.empty())
        {
            TreeNode* node= q.front().first;
            int d= q.front().second;

            q.pop();
            ans= max(ans,d);
            // evry iterratin at 1 time all adjecent can affected so push with +1

            if(node->left && !vis.count(node->left->val))
            {
                q.push({node->left,d+1});
                vis.insert(node->left->val);
            }

            if(node->right && !vis.count(node->right->val))
            {
                q.push({node->right,d+1});
                vis.insert(node->right->val);
            }

            if(mp.count(node) && !vis.count(mp[node]->val))
            {
                q.push({mp[node],d+1});
                vis.insert(mp[node]->val);
            }
        }

        return ans;
    }
};