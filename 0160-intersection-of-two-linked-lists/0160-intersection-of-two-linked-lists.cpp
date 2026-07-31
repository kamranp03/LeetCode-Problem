/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA=0;
        int lenB=0;

        ListNode* tempA=headA;
        ListNode* tempB=headB;

        //calculate 1st list lenght
        while(tempA != NULL)
        {
            lenA++;
            tempA=tempA->next;
        }

        //calculate 2nd list lenght
        while(tempB != NULL)
        {
            lenB++;
            tempB=tempB->next;
        }

        ListNode* p1=headA;
        ListNode* p2=headB;

        //move highest length list pointer by diff
        if(lenA>lenB)
        {
            int diff= lenA- lenB;

            while(diff--)
            {
                p1=p1->next;
            }
        }else{
            int diff= lenB-lenA;
            while(diff--)
            {
                p2=p2->next;
            }
        }

       // traverse list from that untill match
        while(p1 && p2)
        {
            if(p1==p2)
                return p1;

            p1=p1->next;
            p2=p2->next;    
        }
        return NULL;
        
    }
};