class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int> st;

        for(char c : text)
        {
            st[c]++;
        }

        return min({
            st['b'],
            st['a'],
            st['l'] / 2,
            st['o'] / 2,
            st['n']
        });
    }
};