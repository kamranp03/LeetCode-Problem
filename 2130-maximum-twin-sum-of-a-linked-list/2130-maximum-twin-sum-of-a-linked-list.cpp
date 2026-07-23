class Solution {
public:
    int pairSum(ListNode* head) {

        vector<int> res;

        ListNode* temp = head;

        while (temp != NULL) {
            res.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = res.size() - 1;

        int sum = 0;

        while (i < j) {
            sum = max(sum, res[i] + res[j]);

            i++;
            j--;
        }

        return sum;
    }
};