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
    unordered_map<TreeNode*, TreeNode*> mp;
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;

        if(root->left)
            mp[root->left]= root;
        inorder(root->left);

        if(root->right)
            mp[root->right]= root;
        inorder(root->right);
    }

   void bfs(TreeNode* target, int k, vector<int>& res) {
    queue<TreeNode*> q;
    unordered_set<int> vis;
    
    q.push(target); 
    vis.insert(target->val);
    
    while(!q.empty()) {
        int n = q.size();
        
        // Correctly stopping when we reach depth k
        if(k == 0) {
            break;
        }
        
        while(n--) {
            TreeNode* curr = q.front();
            q.pop(); 
            
            if(curr->left && !vis.count(curr->left->val)) {
                q.push(curr->left); 
                vis.insert(curr->left->val); 
            }
            if(curr->right && !vis.count(curr->right->val)) {
                q.push(curr->right); 
                vis.insert(curr->right->val); 
            }
            // Checking the parent pointer
            if(mp.count(curr) && !vis.count(mp[curr]->val)) {
                q.push(mp[curr]); 
                vis.insert(mp[curr]->val); 
            }
        }
        k--; 
    }
    
    // Whatever is left in the queue is exactly distance k away
    while(!q.empty()) {
        TreeNode* t = q.front(); 
        q.pop(); 
        res.push_back(t->val); 
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;

        inorder(root);
        bfs(target,k,res);

        return res;
    }
};