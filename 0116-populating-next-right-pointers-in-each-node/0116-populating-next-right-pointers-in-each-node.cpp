/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {

        // If tree is empty
        if(root == NULL)
            return root;

        // Queue for level order traversal
        queue<Node*> q;
        q.push(root);
        q.push(NULL);  // End of current level

        // Previous node of current level
        Node* prev = NULL;

        while(!q.empty()) {

            // Get front node
            Node* curr = q.front();
            q.pop();

            if(curr == NULL) {

                // Stop after last level
                if(q.empty())
                    break;

                // Mark end of next level
                q.push(NULL);

                // Reset previous node
                prev = NULL;
            }
            else {

                // Add left child
                if(curr->left)
                    q.push(curr->left);

                // Add right child
                if(curr->right)
                    q.push(curr->right);

                // Connect previous node to current
                if(prev != NULL)
                    prev->next = curr;

                // Current becomes previous
                prev = curr;
            }
        }

        return root;
    }
};