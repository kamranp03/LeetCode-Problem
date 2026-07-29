    class Solution {
    public:
        bool check(char ch)
        {
            return ch=='a' || ch=='e' || ch=='i'|| ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I'|| ch=='O' || ch=='U';
        }
        bool halvesAreAlike(string s) {
            int n=s.length();
            int i=0;
            int j=n/2;
            int cntR=0;
            int cntL=0;

            while(i<n/2 && j<n)
            {
                if(check(s[i]))
                    cntL++;
                if(check(s[j]))
                    cntR++;

                i++;
                j++;        
            }
            return cntR==cntL;
        }
    };