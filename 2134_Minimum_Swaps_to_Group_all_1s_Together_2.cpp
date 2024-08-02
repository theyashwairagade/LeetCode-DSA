class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        for(int i=0; i<n; i++){
            if(nums[i])
                count1++;
            nums.push_back(nums[i]);
        }
        n*=2;

        // initializing 
        int current1 = 0;
        for(int i=0; i<count1; i++)
            if(nums[i])
                current1++;
        
        int ans = 0;
        for(int i=count1; i<n; i++){
            ans = max(ans, current1);
            if(nums[i-count1])
                current1--;
            if(nums[i])
                current1++;
        }
        ans = max(ans, current1);

        return count1 - ans;
    }
};