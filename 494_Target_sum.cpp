class Solution {
public:
    int numberOfWays(vector<int>& nums, int index, int target)
    {
        if(!index)
        {
            if(!nums[0] && !target)
                return 2;
            return (nums[0]==target || nums[0]==-target) ? 1 : 0;
        }
        int addition=numberOfWays(nums, index-1, target-nums[index]);
        int subtract=numberOfWays(nums, index-1, target+nums[index]);
        return addition+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return numberOfWays(nums, n-1, target);
    }
};





// To solve overlapping subproblems perform memorization
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};
class Solution {
public:
    int numberOfWays(unordered_map<pair<int,int>,int, pair_hash> &dp, vector<int>& nums, int index, int target)
    {
        if(!index)
            if(!nums[0] && !target)
                return 2;
            else return (nums[0]==target || nums[0]==-target) ? 1 : 0;
        
        if(dp.find({index, target})!=dp.end())
            return dp[{index, target}];
            
        int addition=numberOfWays(dp, nums, index-1, target-nums[index]);
        int subtract=numberOfWays(dp, nums, index-1, target+nums[index]);
        return dp[{index, target}]= addition+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<pair<int,int>,int, pair_hash> dp;
        return numberOfWays(dp, nums, n-1, target);
    }
};