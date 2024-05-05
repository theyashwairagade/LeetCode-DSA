class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        bool have=false;
        prices.push_back(0);
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<prices[i+1] && !have) 
            {
                ans-=prices[i];
                have=true;
            }
            if(prices[i]>prices[i+1] && have)
            {
                ans+=prices[i];
                have=false;
            }
            cout<<ans<<"\t";
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        prices.push_back(0);
        for(int i=1;i<prices.size();i++)
            if(prices[i-1]<prices[i])   ans+=(prices[i]-prices[i-1]);
        return ans;
    }
};