class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int sum = 0;
        priority_queue<int> pq;

        // push into heap and calculate sum
        for (int i = 0; i < piles.size(); i++) {
            pq.push(piles[i]);
            sum += piles[i];
        }

        for (int i = 1; i <= k; i++) {
            int maxE = pq.top();
            int remove_el = maxE / 2;
            pq.pop();

            sum -= remove_el;
            maxE -= remove_el;

            pq.push(maxE);
        }
        return sum;
    }
};