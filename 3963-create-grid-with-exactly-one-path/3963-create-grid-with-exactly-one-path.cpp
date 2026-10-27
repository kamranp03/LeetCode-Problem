class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> s;
        
        // using L pattern( path from starting coloumn and ending row)
        for(int i=0;i<m;i++)
        {
            string str="";
            for(int j=0;j<n;j++)
            {
                if(j==0 || i==m-1)
                {
                    str.push_back('.');
                    continue;
                }

                str.push_back('#');
            }
            s.push_back(str);
        }

        return s;

    }
};