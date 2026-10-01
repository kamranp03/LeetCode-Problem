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
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL) return {};
        q.push(root);

        while (!q.empty()) {

            int lvl = q.size();
           

            // Store current level
            while (lvl--) {

                TreeNode* node = q.front();
                q.pop();
                if (lvl == 0)
                    res.push_back(node->val);

                // Add children for next level
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }
            return res;
        }
    };