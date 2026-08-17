class Solution {
public:
    void solve(int curr, int n, vector<int>& res)
    {
        if(curr>n)
            return;

        res.push_back(curr);

        for(int app=0;app<=9;app++)
        {
            int newnum= curr*10 +app;

            if(newnum>n)
               return;

            solve(newnum,n,res);   
        }    
    }    
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int i=1;i<=9;i++)
        {
            solve(i,n,res);
        }
        return res;
    }
};