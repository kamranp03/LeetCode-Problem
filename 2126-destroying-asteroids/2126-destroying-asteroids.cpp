class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for(int& i: asteroids)
        {
            if(mass< i)
               return false;
            else if(mass>= 1e5)
               return true;
            mass+=i;   
        }
        return true;
    }
};