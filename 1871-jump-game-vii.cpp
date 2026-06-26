class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        queue<int> q;
        q.push(0);

        int maxReach =0;
        
        while(!q.empty())
        {
            int ind= q.front(); q.pop();
            if(ind ==n-1) return true;

            int st= max(ind+minJump, maxReach+1);
            int end= min(ind+maxJump, n-1);

            for(int i=st;i<=end;++i)
            {
                if(s[i] == '0') q.push(i);
            }
            maxReach=end;
        }
        return false;
    }
};