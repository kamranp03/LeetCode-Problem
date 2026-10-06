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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        if(l1->val <= l2->val)
        {
            l1->next= merge(l1->next,l2);
            return l1;
        }else{
            l2->next= merge(l1,l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode* partition(int st,int end,vector<ListNode*>& lists)
    {
        if(st>end) return NULL;

        if(st==end) return lists[st];

        int mid= st+(end-st)/2;

        ListNode* l1= partition(st,mid,lists);
        ListNode* l2= partition(mid+1,end,lists);

        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k= lists.size();
        if(k==0) return NULL;
        return partition(0, k-1, lists);
    }
};