class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices; // Copy original prices
        stack<int> st;               // Stack to store indices

        for (int i = 0; i < n; ++i) {
            // While stack is not empty and the current price is less than or equal 
            // to the price at the index stored at the top of the stack
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int idx = st.top();
                st.pop();
                result[idx] = prices[idx] - prices[i]; // Apply the discount
            }
            st.push(i);
        }

        return result;
    }
};