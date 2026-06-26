class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int op=target[0];
        for(int i=1;i<target.size();i++)
        {
            if(target[i]>target[i-1])
            {
                op+=target[i]-target[i-1];
            }
        }
        return op;
    }
};