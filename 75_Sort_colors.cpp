// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };




// Trying with O(n)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int count0=0, count1=0, count2=0;
//         for(auto &i: nums)
//             if(!i)
//                 count0++;
//             else if(i==1)
//                 count1++;
//             else
//                 count2++;
//         for(auto &i: nums)
//             if(count0)
//                 i=0,
//                 count0--;
//             else if(count1)
//                 i=1,
//                 count1--;
//             else
//                 i=2,
//                 count2--;
//     }
// };





// Using only one pass by Dutch National Flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=n-1;
        for(int i=0; i<=right;)
            if(nums[i]==0)
                swap(nums[left++],nums[i++]);
            else if(nums[i]==1)
                i++;
            else
                swap(nums[right--],nums[i]);
    }
};