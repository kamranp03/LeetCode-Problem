class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()) {

            int lvl = q.size();
            vector<int> curr;

            // Store current level
            for(int i = 0; i < lvl; i++) {

                TreeNode* node = q.front();
                q.pop();

                curr.push_back(node->val);

                // Add children for next level
                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            // Reverse this level if direction is right to left
            if(!flag)
                reverse(curr.begin(), curr.end());

            res.push_back(curr);

            // Change direction
            flag = !flag;
        }

        return res;
    }
};