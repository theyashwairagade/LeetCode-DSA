class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int start1=0,start2=0,length1=nums1.size(), length2=nums2.size();
        while(start1<length1 && start2<length2)
            if(nums1[start1]==nums2[start2])    return nums1[start1];
            else if(nums1[start1]<nums2[start2]) start1++;
            else    start2++;
        return -1;
    }
};