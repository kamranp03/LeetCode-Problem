class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk= numBottles;
        int empty= numBottles;
        int p=0;

        while(empty>=numExchange)
        {
            empty= empty-numExchange+1;
            numExchange+=1;
            p++;
        }
        return drunk+p;
    }
};