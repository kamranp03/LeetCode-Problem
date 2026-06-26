class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> spec;

        int start=0;
        int sum=0;

        for(int i=0;i<s.length();i++)
        {
            sum+= s[i]== '1' ? 1 : -1;

            if(sum==0)
            {
                string inner = s.substr(start+1, i-start-1);
                spec.push_back("1" + makeLargestSpecial(inner) + "0");
                start= i+1;
            }
        }

        sort(begin(spec), end(spec), greater<string>());

        string res;
        for(string &ss: spec)
        {
            res+=ss;
        }

        return res;
    }
};