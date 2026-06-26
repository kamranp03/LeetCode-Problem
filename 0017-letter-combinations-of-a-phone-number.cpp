class Solution {
public:
  unordered_map<char,string> f = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};

    void phone(string digits, int n, int idx, string diary, vector<string> &res)
    {
        if(idx==n)
        {
            res.push_back(diary);
            return;
        }

        string choice=f[digits[idx]];

        for(int j=0;j<choice.size();j++)
        {
            diary.push_back(choice[j]);
            phone(digits, n, idx+1,diary,res);
            diary.pop_back();

        }
        return;

    }
    vector<string> letterCombinations(string digits) {
        int idx=0;
        int n=digits.size();
        vector<string> res;
        string diary="";
        phone(digits, n, idx ,diary, res);

        return res;
    }
};