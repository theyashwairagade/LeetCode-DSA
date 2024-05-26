class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int length=nums.size()/2;
        int prev=nums[0]+nums[1];
        for(int i=1;i<length;i++)
        {
            int j=2*i;
            if(prev!=(nums[j]+nums[j+1]))    return i;
        }
        return length;
    }
};