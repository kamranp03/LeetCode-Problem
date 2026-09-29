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
 ListNode* reverse(ListNode* curr)
    {
        if(curr == NULL || curr->next == NULL)
        {
            return curr;
        }

        ListNode* prev = NULL;

        while(curr != NULL)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1= reverse(l1);
        l2= reverse(l2);

        int sum=0;
        int carry=0;
        ListNode* ans= new ListNode();
        while( l1 != NULL || l2 != NULL)
        {
            if(l1)
            {
                sum+= l1->val;
                l1=l1->next;
            }

            if(l2)
            {
                sum+= l2->val;
                l2=l2->next;
            }

            ans->val= sum%10;
            carry= sum/10;

            ListNode* newNode= new ListNode(carry);
            newNode->next= ans;
            ans= newNode;
            sum=carry;
        }

        return carry==0 ? ans->next: ans;
    }
};