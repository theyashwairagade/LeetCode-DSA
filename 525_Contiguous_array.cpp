class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mapping;
        mapping[0]=-1;
        
        int ans=0, sum=0;
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            if(nums[i])  sum++;
            else    sum--;
            auto it = mapping.find(sum);

            if (it != mapping.end())    ans=max(ans,i-mapping[sum]);
            else    mapping[sum]=i;
        }
        return ans;
    }
};