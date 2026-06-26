class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.length();

        int coll=0;
       int i=0;

       while(i<n && directions[i]=='L') i++;// skipLeftCar
       
       int j=n-1;
       while(j>=0&& directions[j]=='R') j--;// skipRightCar
       

       for(int l=i;l<=j;l++)
       {
        if(directions[l] !='S')
        {
            coll++;
        }
        
       }


        return coll;
    }
};