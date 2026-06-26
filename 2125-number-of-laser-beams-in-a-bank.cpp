class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;  // count of devices in the previous non-empty row
        int result = 0;

        for (string& row : bank) {
            int curr = count(row.begin(), row.end(), '1');  // count devices in this row
            if (curr == 0) continue;  // skip empty rows

            if (prev > 0) {
                result += prev * curr;  // beams between previous and current row
            }
            prev = curr;  // update previous row
        }
        return result;
    }
};
