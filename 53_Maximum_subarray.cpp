// Later try using divide and conquer approach

// Brutte force by me
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, sum=0;
        for(const int &num: nums)
        {
            if(num>=0)  sum+=num;
            else    sum=max(0,sum+num);

            if(sum>0)   ans=max(ans,sum);
            else        ans=max(ans,num);
        }
        return ans;
    }
};


// Simpler logic
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, sum=0;
        for(const int &num: nums)
        {
            sum+=num;
            ans=max(ans,sum);
            sum=max(sum,0);
        }
        return ans;
    }
};