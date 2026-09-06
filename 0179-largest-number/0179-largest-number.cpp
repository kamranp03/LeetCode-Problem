class Solution {
public:
    // compare numbers like here - 10 <4 like we get 410 larger that 104
    static bool compare(int a, int b) {
        string x = to_string(a);
        string y = to_string(b);

        //9>10;
        return x + y > y + x;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        string res = "";

        for(int x : nums) {
            res += to_string(x);
        }

        // If all numbers are 0
        if(res[0] == '0')
            return "0";

        return res;
    }
};