// Brutforce using prefix sum time complexity is O(n) and space complexity is O(n)
// and optimized with time complexity as O(n) and space complexity as O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero=0, len=nums.size();
        for(int num:nums)
        {
            if(!num)    countZero++;
            if(countZero>1) break;
        }
        if(countZero>1) return vector<int>(len,0);
        if(countZero==1)
        {
            vector<int> ans(len,0);
            int product=1,index;
            for(int i=0;i<len;i++)
                if(nums[i]) product*=nums[i];
                else    index=i;
            ans[index]=product;
            return ans;
        }
        // Brutforce
        // vector<int> first(len,1),second(len,1);
        // for(int i=1;i<len;i++)
        //     first[i]=first[i-1]*nums[i-1];
        // for(int i=len-2;i>=0;i--)
        //     second[i]=second[i+1]*nums[i+1];
        // for(int i=0;i<len;i++)
        //     second[i]*=first[i];
        // return second;

        // Optimised
        vector<int> ans(len,1);
        int multiplier=1;
        for(int i=1;i<len;i++)
            ans[i]=ans[i-1]*nums[i-1];
        for(int i=len-2;i>=0;i--)
            ans[i]*=multiplier*=nums[i+1];
        return ans;
    }
};