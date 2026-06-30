class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        ListNode* temp = head;

        while(temp)
        {
            if(temp->val < x)
            {
                small->next = temp;
                small = small->next;
            }
            else
            {
                large->next = temp;
                large = large->next;
            }

            temp = temp->next;
        }

        large->next = NULL;

        small->next = largeDummy->next;

        return smallDummy->next;
    }
};