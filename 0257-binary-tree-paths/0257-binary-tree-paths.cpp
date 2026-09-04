class Solution {
public:
    void backtrack(TreeNode* root, string s, vector<string>& res)
    {
        if(root == NULL)
            return;

        // Add current node
        s += to_string(root->val);

        // Leaf node
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(s);
            return;
        }

        // ARROW
        s += "->";

        backtrack(root->left, s, res);
        backtrack(root->right, s, res);
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        string s;

        backtrack(root, s, res);

        return res;
    }
};