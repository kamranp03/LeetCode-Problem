class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty or single node
        if(head == NULL || head->next == NULL)
            return head;

        // Find length and last node
        int len = 1;
        ListNode* temp = head;

        while(temp->next != NULL)
        {
            len++;
            temp = temp->next;
        }

        // Remove unnecessary rotations
        k = k % len;

        if(k == 0)
            return head;

        // Find new tail
        int steps = len - k;
        ListNode* prev = head;

        while(steps > 1)
        {
            prev = prev->next;
            steps--;
        }

        // New head is after new tail
        ListNode* newHead = prev->next;

        // Break the list
        prev->next = NULL;

        // Connect old tail to old head
        temp->next = head;

        return newHead;
    }
};