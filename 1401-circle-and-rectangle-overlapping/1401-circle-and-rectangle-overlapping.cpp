class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2,
                      int y2) {

        int xi, yi;

        if (x1 > xc) {
            xi = x1;
        } else if (xc > x2) {
            xi = x2;
        } else {
            xi = xc;
        }

        if (y1 > yc) {
            yi = y1;
        } else if (yc > y2) {
            yi = y2;
        } else {
            yi = yc;
        }

        return sqrt((xi - xc) * (xi - xc) + (yi - yc) * (yi - yc)) <= radius;
    }
};