class Solution {
public:
    int minimumPushes(string word) {
        int size = word.length();
        if (size <= 8) {
            return size;

        } else if (size > 8 && size <= 16) {
            return 8 + (size - 8) * 2;
        } else if (size > 16 && size <= 24) {
            return 24 + (size - 16) * 3;
        } else {
            return 48 + (size - 24) * 4;
        }
        return -1;
    }
};