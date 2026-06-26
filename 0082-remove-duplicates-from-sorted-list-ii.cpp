class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        unordered_map<int,int> mp;
        
        ListNode* temp = head;
        
        // count frequency
        while(temp != NULL)
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        temp = head;
        
        while(temp != NULL)
        {
            if(mp[temp->val] == 1)
            {
                tail->next = temp;
                tail = tail->next;
            }
            
            temp = temp->next;
        }
        
        tail->next = NULL;
        
        return dummy->next;
    }
};