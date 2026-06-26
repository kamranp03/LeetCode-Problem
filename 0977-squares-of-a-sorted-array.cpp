class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int no=nums.size();

        vector<int> pos;
        vector<int> neg;

        // devide the array

        for(int i=0;i<no;i++)
        {
            if(nums[i]>=0)
               pos.push_back(nums[i]);
            else
               neg.push_back(nums[i]);   
        }

        //No negetive num
        if(neg.size()==0)
        {
            for(int i=0;i<no;i++)
               nums[i]=nums[i]*nums[i];

            return nums;   
        }

        //no positive num
        if(pos.size()==0)
        {
            for(int i=0;i<no;i++)
               nums[i]=nums[i]*nums[i];


            reverse(nums.begin(), nums.end());   
            return nums;   
        }

        //array contain both 

        int i=0;
        int j=0;
        int m=pos.size();
        int n=neg.size();
        int id=0;
        vector<int> res(m+n);

        // sq pos array
        for(int i=0;i<m;i++)
            pos[i]=pos[i]*pos[i];

        //sq neg array
        for(int j=0;j<n;j++)
            neg[j]=neg[j]*neg[j];
        reverse(neg.begin(), neg.end());


        while(i<m && j<n)
        {
            if(pos[i]<neg[j])
            {
                res[id]=pos[i];
                i++;
                id++;
            }else{
                res[id]=neg[j];
                j++;
                id++;
            }
        }

        //remaining pos
        while(i<m)
        {
            res[id]=pos[i];
                i++;
                id++;
        }
        //remaining neg
        while(j<n)
        {
            res[id]=neg[j];
                j++;
                id++;
        }

        return res;
    }
};