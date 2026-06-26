class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(int a:apple)
        {
            total+=a;
        }

        sort(capacity.begin(),capacity.end(),greater<int>());

        int used=0;
        int count=0;

        for( int c: capacity)
        {
            used+=c;
            count++;

            if(used>=total)
            {
                break;
            }
        }
        return count;
    }
};