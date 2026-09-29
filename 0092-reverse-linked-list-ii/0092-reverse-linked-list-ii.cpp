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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* temp = head;

        ListNode* lft = NULL;
        ListNode* rght = NULL;
        ListNode* prevL = NULL;
        ListNode* nextR = NULL;

        int count = 1;

        // Find left, right and their surrounding nodes
        while(temp != NULL) {

            if(count == left) {
                lft = temp;
            }

            if(count == right) {
                rght = temp;
                nextR = temp->next;
            }

            if(count == left - 1) {
                prevL = temp;
            }

            temp = temp->next;
            count++;
        }

        // Reverse from left to right
        ListNode* curr = lft;
        ListNode* prev = nextR;

        while(curr != nextR) {

            ListNode* nxt = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        if(prevL != NULL)
            prevL->next = prev;
        else
            head = prev;

        return head;
    }
};