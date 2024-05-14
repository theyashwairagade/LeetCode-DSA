class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length=cost.size();
        for(int i=length-3;i>=0;i--)
            cost[i]+=min(cost[i+1],cost[i+2]);
        return min(cost[0],cost[1]);
    }
};