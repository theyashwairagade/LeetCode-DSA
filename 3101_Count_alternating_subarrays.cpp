class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=1;
        int lastOccurenceIndex=-1,n=nums.size();
        for(int i=1;i<n;i++)
            if(nums[i]==nums[i-1])  lastOccurenceIndex=i-1,ans++;
            else    ans+=i-lastOccurenceIndex;
        return ans;
    }
};