class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for(int HH=0; HH<=11;HH++)
        {
            for(int MM=0;MM<=59;MM++)
            {
                if(__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn)
                {
                    string h= to_string(HH);
                    string m= (MM <10 ? "0" : "") + to_string(MM);

                    res.push_back(h+ ":" + m);
                }
            }
        }
        return res;
        
    }
};