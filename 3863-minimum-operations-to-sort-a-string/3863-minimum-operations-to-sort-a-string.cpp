class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string temp = s;

        sort(temp.begin(), temp.end());

        if (s == temp)
            return 0;
        if (n <= 2)
            return -1;

        char mn = temp[0];
        char mx = temp[n - 1];

        if (s[0] == mn || s[n - 1] == mx) // if one is on currect pposition , so
                                          // only one operation is there
            return 1;

        //// Check if mn doesn't exist in any proper prefix and mx doesn't exist in any proper suffix            
        bool mn_in_pre=false; //
        bool mx_in_suf=false;

        for(int i=0;i<n-1;i++)
        {
            if(s[i]==mn) mn_in_pre=true;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]==mx) mx_in_suf=true;
        }

        // mn&mx not in proper pre and suf then quaranteed 3 op requere
        if(!mn_in_pre && !mx_in_suf) return 3;

        // if any one it is there 
        return 2;
    }
};