class Solution {
public:
    int findIdx(int n,int k)
    {
        if(n==1)
            return 0;

        int idx= findIdx(n-1,k);
        idx= (idx+k)%n;

        return idx ;   
    }
    int findTheWinner(int n, int k) {
        int rrs= findIdx(n,k);

        return rrs+1;
    }
};