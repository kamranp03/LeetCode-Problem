
// Approach 1-> travers from both side 
// Tc- O(n) Sc- O(n)

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n= ratings.size();
//         vector<int> count(n,1);

//         //left tp right
//         for(int i=1;i<n;i++)
//         {
//             if(ratings[i]>ratings[i-1])
//             {
//                 count[i]= max(count[i], count[i]+1);
//             }
//         }
//         // right to left
//         for(int i=n-2;i>=0;i--)
//         {
//             if(ratings[i]>ratings[i+1])
//             {
//                 count[i]= max(count[i], count[i]+1);
//             }
//         }

//         int res=0;

//         for(int i=0;i<n;i++)
//         {
//             res+= count[i];
//         }
//         return res;
//     };
// };

// ----------------------------------------------------------------------------------------------------

// Approach 2 -> Tc o(n) sc= o(1)  checking peak and dip

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int candy =n;

        int i=1;

        while(i<n)
        {
            //flat surface
            if(ratings[i]==ratings[i-1])
            {
                i++;
                continue;
            }

            int peak=0;
            // up surface
            while(ratings[i]>ratings[i-1])
            {
                peak++;
                candy+= peak;
                i++;
                if(i==n) return candy;
            }

            int dip=0;
            // down surface
            while(i<n && ratings[i]<ratings[i-1])
            {
                dip++;
                candy+= dip;
                i++;
            }

            //mountain complete 
            // then only one value need to be add in candy so minus minumun value

            candy-= min(peak,dip);
        }

        return candy;
    }
};