class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        int hired=0,i=0,j=costs.size()-1;
        priority_queue<int, vector<int>, greater<int>> pq1,pq2;

        while(hired<k)
        {
            while(pq1.size()<candidates && i<=j)
            {
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates && j>=i)
            {
                pq2.push(costs[j]);
                j--;
            }

            int min_1= pq1.size()>0 ? pq1.top(): INT_MAX;
            int min_2= pq2.size()>0 ? pq2.top(): INT_MAX;

            if(min_1<= min_2)
            {
                ans+= min_1;
                pq1.pop();
            }else{
                ans+= min_2;
                pq2.pop();
            }
            hired++;
        }
        return ans;
    }
};