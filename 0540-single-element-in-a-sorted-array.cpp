class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];

        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Boundary checks first
            if (mid == 0 && a[mid] != a[mid + 1]) return a[mid];
            if (mid == n - 1 && a[mid] != a[mid - 1]) return a[mid];

            // Check for single element in middle
            if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1])
                return a[mid];

            // Binary search logic
            if ((mid % 2 == 0 && a[mid] == a[mid + 1]) ||
                (mid % 2 == 1 && a[mid] == a[mid - 1])) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; // should never reach here
    }
};
