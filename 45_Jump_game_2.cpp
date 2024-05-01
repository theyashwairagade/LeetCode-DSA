// Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0, curEnd=0, farthest=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            farthest=max(farthest,i+nums[i]);
            if(i==curEnd)
            {
                steps++;
                curEnd=farthest;
            }
        }
        return steps;
    }
};


// memonization
class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
            nums[i]=max(nums[i]+i,nums[i-1]);
        int ans=0;
        for(int i=0;i<nums.size()-1;)
        {
            ans++;
            i=nums[i];
        }
        return ans;
    }
};