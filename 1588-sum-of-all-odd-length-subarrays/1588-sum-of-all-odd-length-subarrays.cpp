class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int total =(i+1)*(n-i);
            int oddcnt=(total+1)/2;
            res+=oddcnt* arr[i];
        }
        return res;
    }
};