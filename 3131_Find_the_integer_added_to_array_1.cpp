class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int min1=nums1[0], min2=nums2[0], len=nums1.size();
        for(int i=1;i<len;i++)
        {
            min1=min(min1,nums1[i]);
            min2=min(min2,nums2[i]);
        }
        return min2-min1;
    }
};