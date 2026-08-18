class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0; // total time required

        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) // for the persons before the k
            {
                total += min(tickets[i],
                             tickets[k]); // whose are the minimum tickets they
                                          // are calculated, dry run
            }

            else {
                total += min(tickets[i],
                             tickets[k] -
                                 1); // for persons after k we only need them
                                     // till k's last ticket therefore k-1
            }
        }

        return total;
    }
};