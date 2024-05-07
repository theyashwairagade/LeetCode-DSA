// Brute Force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        k%=len;
        if(!k)  return;
        vector<int> ans;
        for(int i=len-k;i<len;i++)  ans.push_back(nums[i]);
        for(int i=0;i<len-k;i++)    ans.push_back(nums[i]);
        for(int i=0;i<len;i++)  nums[i]=ans[i];
    }
};


// Using reverse function
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        k%=len;
        if(!k)  return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};