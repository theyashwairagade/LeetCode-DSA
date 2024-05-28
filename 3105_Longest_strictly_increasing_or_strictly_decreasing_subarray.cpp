class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0,n=nums.size();
        int increasing =1, decreasing =1;
        if(n)   
            ans=1;
        for(int i=1;i<n;i++)
            if(nums[i-1]==nums[i])  
                increasing=1,
                decreasing=1,
                ans=max(ans,1);
            else if(nums[i-1]<nums[i])  
                increasing ++, 
                decreasing=1, 
                ans=max(ans,increasing);
            else    
                decreasing++, 
                increasing=1, 
                ans=max(ans,decreasing);
        return ans;
    }
};