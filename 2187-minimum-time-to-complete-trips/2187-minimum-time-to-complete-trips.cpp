class Solution {
public:
    bool possible(vector<int>& time, long long given, int totalTrips)
    {
        long long actual=0;

        for(int &t: time)
        {
            actual += given/t;
        }
        return actual>= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();

        long long l=1;
        long long r= (long long) *min_element(time.begin(), time.end()) * totalTrips;

        while(l<r)
        {
            long long mid= l+( r-l)/2;

            if(possible(time, mid, totalTrips))
            {
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};