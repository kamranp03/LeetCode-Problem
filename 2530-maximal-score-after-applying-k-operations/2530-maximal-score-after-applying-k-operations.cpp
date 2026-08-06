class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum=0;

        priority_queue<int> pq(nums.begin(), nums.end()); // heapify o(n)

        while(k--)
        {
            int num=pq.top();
            pq.pop();
            sum+= num;

            num=ceil(num/3.0);
            pq.push(num);
        }
        return sum;
    }
};