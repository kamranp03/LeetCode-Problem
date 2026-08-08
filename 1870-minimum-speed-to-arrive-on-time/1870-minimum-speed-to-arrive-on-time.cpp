class Solution {
public:
    //TC-> toatal = o(nlogk)
    double possible(vector<int>& dist,int mid)
    {
        double time=0.0;
        int n=dist.size();
        for(int i=0;i<n-1;i++) //o(n)
        {
            double t= (double) dist[i]/ (double) mid;
            time+= ceil(t);
        }
        time+= (double) dist[n-1] / (double) mid;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=1;
        int r= 1e7;
        int res=-1;
        //o(logk)
        while(l<=r)
        {
            int mid= l+(r-l)/2;

            if(possible(dist,mid)<= hour)
            {
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
        }
};