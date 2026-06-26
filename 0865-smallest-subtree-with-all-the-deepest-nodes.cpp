class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (root == NULL)
            return {0, NULL};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If both sides have same depth
        if (left.first == right.first) {
            return {left.first + 1, root};
        }
        // Left side deeper
        else if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        // Right side deeper
        else {
            return {right.first + 1, right.second};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
