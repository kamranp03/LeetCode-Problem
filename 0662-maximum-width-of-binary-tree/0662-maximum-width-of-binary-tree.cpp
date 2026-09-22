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
    int widthOfBinaryTree(TreeNode* root) {

        // Queue stores {node, index}
        queue<pair<TreeNode*, long long>> q;

        // Root starts at index 0
        q.push({root, 0});

        int maxD = 0;

        while(!q.empty()) {

            int lvl = q.size();

            // First index of current level
            long long first = q.front().second;

            long long last = 0;

            for(int i = 0; i < lvl; i++) {

                // Get node
                TreeNode* curr = q.front().first;

                // Reset index from 0 for this level
                long long idx = q.front().second - first;

                q.pop();

                // Last index of this level
                last = idx;

                // Left child
                if(curr->left)
                    q.push({curr->left, 2 * idx + 1});

                // Right child
                if(curr->right)
                    q.push({curr->right, 2 * idx + 2});
            }

            // Width = last index - first index + 1
            maxD = max(maxD, (int)(last + 1));
        }

        return maxD;
    }
};

/*
Logic:

Use BFS (level order) using a queue.

Normally BFS only stores:
    node

But here we also store:
    {node, index}

Why index?
Because width includes NULL positions between two nodes.

Imagine a Complete Binary Tree:

             0
           /   \
          1     2
        /  \   /  \
       3   4  5    6

Index formula:
    left  = 2 * index + 1
    right = 2 * index + 2

For every level:
    st  = index of first node
    end = index of last node

    width = end - st + 1

Then update maximum width.

Important:
We don't put NULL nodes into the queue.
Their positions are automatically represented by the indexes.

So:
    BFS + Indexing + (end - st + 1)
*/