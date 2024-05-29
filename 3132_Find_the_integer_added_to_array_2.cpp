class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int len1=nums1.size(), len2=nums2.size();
        
        if(len1==3)  return nums2[0]-nums1[2];
        
        int consider, ignore, iterator1, iterator2;
        
        consider=nums2[0]-nums1[2];
        iterator1=0, iterator2=0;
        
        for(ignore=3;ignore && iterator1<len1 && iterator2<len2; iterator1++)
        {
            if(nums1[iterator1]+consider==nums2[iterator2]) iterator2++;
            else    ignore--;
        }
        if(ignore)  return consider;
        
        consider=nums2[0]-nums1[1];
        iterator1=0, iterator2=0;
        
        for(ignore=3;ignore && iterator1<len1 && iterator2<len2; iterator1++)
        {
            if(nums1[iterator1]+consider==nums2[iterator2]) iterator2++;
            else    ignore--;
        }
        if(ignore)  return consider;
        
        consider=nums2[0]-nums1[0];
        return consider;
    }
};