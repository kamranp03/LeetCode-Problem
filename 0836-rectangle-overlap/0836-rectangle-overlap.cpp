class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int lef1_x = rec1[0];
        int lef1_y = rec1[1];
        int right1_x = rec1[2];
        int right1_y = rec1[3];

        int lef2_x = rec2[0];
        int lef2_y = rec2[1];
        int right2_x = rec2[2];
        int right2_y = rec2[3];

        if (lef2_x >= right1_x)
            return false;
        if (lef1_x >= right2_x)
            return false;

        if (lef2_y >= right1_y)
            return false;
        if (lef1_y >= right2_y)
            return false;

        return true;
    }
};