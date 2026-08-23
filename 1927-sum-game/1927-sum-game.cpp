class Solution {
public:
    //check Notebook for formula formation
    bool sumGame(string num) {
        int leftSum = 0;
        int rightSum = 0;
        int leftQ = 0;
        int rightQ = 0;

        int n = num.length();

        // Calculate sum and '?' in left half
        for(int i = 0; i < n / 2; i++)
        {
            if(num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        // Calculate sum and '?' in right half
        for(int i = n / 2; i < n; i++)
        {
            if(num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int diff = leftSum - rightSum;

        // Extra '?' on right (+) or left (-)
        int qDiff = rightQ - leftQ;

        // Every 2 extra '?' create a difference of 9
        int target = 9 * qDiff / 2;

        // Odd extra '?' -> Alice can always break equality
        if(qDiff % 2 != 0)
            return true;
            
        // If difference can be forced to 0, Bob wins.
        // Otherwise Alice wins.
        return diff != target;
    }
};