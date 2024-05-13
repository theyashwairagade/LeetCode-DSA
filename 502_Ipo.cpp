// It's two heap approach but instead of one heap we just sort
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> minCapital;
        priority_queue<int> maxProfit;

        int n=profits.size();
        for(int i=0;i<n;i++)
            minCapital.push_back(make_pair(capital[i],profits[i]));
        sort(minCapital.begin(),minCapital.end());
        
        int i=0;
        while(k--)
        {
            while(i<n && minCapital[i].first<=w)
                maxProfit.push(minCapital[i++].second);
            
            if(maxProfit.empty())   return w;
            w+=maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};



