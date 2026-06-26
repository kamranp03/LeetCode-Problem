class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* second = reverse(slow);

        // Step 3: Compare
        ListNode* first = head;
        while(second) {
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};