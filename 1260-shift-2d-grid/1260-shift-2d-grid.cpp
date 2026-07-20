class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int sz=n*m;

        k=k%sz;

        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int nwidx=i*m+j+k;
                int nwrow= (nwidx/m) % n;
                int nwcol= nwidx%m;

                ans[nwrow][nwcol]=grid[i][j];
            }
        }
        return ans;

    }
};