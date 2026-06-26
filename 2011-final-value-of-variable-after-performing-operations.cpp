class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int n=op.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            if(op[i]=="++x" || op[i]=="++X" || op[i]=="x++" || op[i]=="X++")
            {
                total++;
            }
            else{
                total--;
            }
        }
        return total;
    }
};