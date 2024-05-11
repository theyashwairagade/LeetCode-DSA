class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num3;
        int s1=nums1.size(),s2=nums2.size();
        for(int i=0;i<s1;i++)   for(int j=0;j<s2;j++)
        if(nums1[i]==nums2[j] && nums1[i]>=0)
        {
            num3.push_back(nums1[i]);
            nums1[i]=nums2[j]=-1;
        }
        return num3;
    }
};