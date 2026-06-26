class Solution {
public:
    int maximumSum(vector<int>& a) {
        int noDel = a[0];
        int oneDel = INT_MIN;
        int res = a[0];

        for (int i = 1; i < a.size(); i++) {
            int prevNo = noDel;

            noDel = max(a[i], noDel + a[i]);
            if (oneDel != INT_MIN)
                oneDel = max(prevNo, oneDel + a[i]);
            else
                oneDel = prevNo;
            res = max(res, max(noDel, oneDel));
        }
        return res;
    }
};