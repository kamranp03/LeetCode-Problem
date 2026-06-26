class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        
        int even_count = 0;
        int odd_count = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
               
                answer[i] = odd_count;
                even_count++;
            } else {
                
                answer[i] = even_count;
                odd_count++;
            }
        }
        
        return answer;
    }
};