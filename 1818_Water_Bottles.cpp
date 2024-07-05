class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int ans = 0;
        while(numBottles){
            emptyBottles += numBottles;
            ans += numBottles;

            numBottles = emptyBottles / numExchange;
            emptyBottles %= numExchange;
        }
        return ans;
    }
};