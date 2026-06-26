class Solution {
public:
    int M=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        int t[m+1][n+1][k+1];
        memset(t,0,sizeof(t));

        for(int rem=0;rem<=k-1;rem++)
        {
            t[m-1][n-1][rem]=(rem+grid[m-1][n-1])%k ==0;
        }

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                for(int rem=0;rem<=k-1;rem++)
                {
                    if(i==m-1 && j==n-1)
                    continue;

                    int R=(rem+grid[i][j])%k;

                    int down=t[i+1][j][R];
                    int right=t[i][j+1][R];

                    t[i][j][rem]=(down +right) %M;
                }
            }
        }
        return t[0][0][0];
    }
};