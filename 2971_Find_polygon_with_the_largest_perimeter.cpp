class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum=0, ans=-1;
        for(int number: nums)
        {   if(number<sum)  ans=number+sum;
            sum+=number;
        }
        return ans;
    }
};