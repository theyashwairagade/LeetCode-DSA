// kadane's Algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,min=prices[0];
        for(int price:prices)
        {
            if(price<min)   min=price;
            if(price-min>profit)    profit=price-min;
        }
        return profit;
    }
};