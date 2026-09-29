class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while(l1 != NULL || l2 != NULL || carry)
        {
            int sum = carry;

            // Add l1 digit
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add l2 digit
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Store current digit
            curr->next = new ListNode(sum % 10);

            // Move to next result node
            curr = curr->next;

            // Store carry
            carry = sum / 10;
        }

        return ans->next;
    }
};