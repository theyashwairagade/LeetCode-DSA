class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0)
                return false;

        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int left=INT_MAX, right=INT_MIN;
        bool changed=false;
        unordered_map<int,bool> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())  mp[nums[i]]=isPrime(nums[i]);
            if(mp[nums[i]])     left=min(left,i), right=max(right,i), changed=true;
        }
        if(changed) return right-left;
        else    return 0;
    }
};