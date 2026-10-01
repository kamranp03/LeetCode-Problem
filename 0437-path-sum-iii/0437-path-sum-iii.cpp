class Solution {
public:
    int count(TreeNode* root, long long targetSum) {
        if (root == NULL)
            return 0;

        int res = 0;

        // We got path which has target sum
        if (root->val == targetSum)
            res++;

        // Check both sides
        res += count(root->left, targetSum - root->val);
        res += count(root->right, targetSum - root->val);

        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        // Try every node as a starting point
        return count(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};