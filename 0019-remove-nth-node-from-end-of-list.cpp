/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //find length
       int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // Step 2: If head needs to be removed
        if (n == len) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Step 3: Traverse to the node before the one to be deleted
        int pos = len - n;
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Step 4: Delete the target node
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};