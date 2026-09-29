class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while(curr != NULL)
        {
            ListNode* nxt = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Merge both halves
        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL)
        {
            ListNode* nxt1 = first->next;
            ListNode* nxt2 = second->next;

            first->next = second;
            second->next = nxt1;

            first = nxt1;
            second = nxt2;
        }
    }
};