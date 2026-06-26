class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        vector<int> cum(n,0);
        cum[0]=(s[0]=='1')?1:0;

        for(int i=1;i<n;i++)
        {
            cum[i]=cum[i-1]+((s[i]=='1')?1:0);
        }

        int res=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int one=cum[j]-(i-1>=0?cum[i-1]:0);
                int zero=(j-i+1) -one;

                if((zero*zero)>one)
                {
                    // avoid extra index 
                    int extra=(zero*zero)-one;
                    j+=extra-1;
                }else if((zero*zero)==one){
                    res+=1;
                }else{
                    //(zero*zero)<one

                    res+=1;

                    int k=sqrt(one)-zero;

                    int next=j+k;

                    if(next>=n)
                    {
                        res+=(n-j-1);
                        break;
                    }else{
                        res+=k;
                    }
                    j=next;
                }
            }
        }
        return res;

    }
};