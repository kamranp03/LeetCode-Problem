class Solution {
public:
    TreeNode* ans = NULL;

    int lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return 0;

        int left = lca(root->left, p, q);
        int right = lca(root->right, p, q);

        int self = 0;

        if (root == p || root == q)
            self = 1;

        int total = left + right + self;

        if (total == 2 && ans == NULL)
            ans = root;

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return ans;
    }
};