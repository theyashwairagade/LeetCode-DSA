class Solution {
public:
    int maxBottlesDrunk(int fullBottles, int exchange) {
        int empty=0,ans=0;
        while(fullBottles || (empty>=exchange && exchange))
        {
            while(empty>=exchange)
            {
                fullBottles++;
                empty-=exchange;
                exchange++;
            }
            ans+=fullBottles;
            empty+=fullBottles;
            fullBottles=0;
        }
        
        return ans;
    }
};