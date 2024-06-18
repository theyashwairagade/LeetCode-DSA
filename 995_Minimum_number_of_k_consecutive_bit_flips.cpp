class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n= nums.size();
        vector<bool> prevFlipped;
        bool currentFlipped= false;

        int ans = 0;
        for(int i= 0; i<= n -k; i++)
        {
            if(i-k>=0)
                currentFlipped ^=prevFlipped[i-k];
            if((!currentFlipped && !nums[i]) || (currentFlipped && nums[i]))
                prevFlipped.push_back(true),
                currentFlipped^=1,
                ans++;
            else
                prevFlipped.push_back(false);
        }
        for(int i= n-k+1; i<n; i++)
        {
            if(i-k>=0)
                currentFlipped ^=prevFlipped[i-k];
            if((!currentFlipped && !nums[i]) || (currentFlipped && nums[i]))
                return -1;
        }
        return ans;
    }
};