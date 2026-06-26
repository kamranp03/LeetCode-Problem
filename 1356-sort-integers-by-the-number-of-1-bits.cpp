class Solution {
public:

    int countOnes(int x)
    {
        int c=0;
        while(x)
        {
            x &=(x-1);
            c++;
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int ca= countOnes(a);
            int cb= countOnes(b);

            if(ca== cb)
               return a<b;

             return ca<cb;  
        });

        return arr;
    }
};