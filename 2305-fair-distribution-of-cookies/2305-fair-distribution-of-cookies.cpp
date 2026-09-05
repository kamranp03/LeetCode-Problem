class Solution {
public:
    int res=INT_MAX;

    void solve(int idx, vector<int>& child, vector<int>& cookies, int k)
    {
        if(idx>=cookies.size())
        {
            int maxi= *max_element(child.begin(),child.end());
            res= min(maxi,res);
            return;
        }

        int cookie= cookies[idx];
        for(int i=0;i<k;i++)
        {
            child[i]+=cookie;
            solve(idx+1,child,cookies,k);
            child[i]-=cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k,0);
        solve(0,child,cookies,k);
        return res;
    }
};