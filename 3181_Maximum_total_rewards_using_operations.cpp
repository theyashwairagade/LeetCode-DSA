class Solution {
    int mostSignificantBit(bitset <100100> btst)
    {
        int ans = btst.size()-1;
        while(!btst[ans])
            ans--;
        return ans;
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort (rewardValues.begin(), rewardValues.end());
        bitset <100100> ans;
        ans[0]=1;
        int i = 0;
        bitset <100100> ander;
        for(int reward : rewardValues)
        {
            while (i < reward)
                ander.set(i++);
            ans |= (ans & ander) << reward;
        }
        return mostSignificantBit(ans);
    }
};