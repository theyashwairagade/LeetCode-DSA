// Brutte force with time complexity of O(n) and space complexity of O(n)
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int k = 3;
//         int n = nums.size(), ans = 0;
//         for(int i=0; i <= n-k; i++)
//             if(!nums[i] && ++ans)
//                 for(int j= i; j<i+k; j++)
//                     nums[j]= nums[j] ^ 1 ;
//         for(int i = n - k +1; i<n; i++)
//             if(!nums[i])
//                 return -1;
//         return ans;
//     }
// };





// optimizing so that it is not limited to only k=3;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size(), k = 3;
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