// Simple merge sort in another array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int first=0,second=0;
        while(first<m && second<n)
            if(nums1[first]<nums2[second])  ans.push_back(nums1[first++]);
            else    ans.push_back(nums2[second++]);
        while(first<m)  ans.push_back(nums1[first++]);
        while(second<n) ans.push_back(nums2[second++]);
        for(int i=0;i<m+n;i++)
            nums1[i]=ans[i];
    }
};

// simple merge sort from end
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--;
        n--;
        while(m>=0 && n>=0)
            if(nums1[m]>nums2[n])   nums1[m+n+2]=nums1[m--];
            else    nums1[m+n+2]=nums2[n--];
        while(n>=0){
            nums1[n]=nums2[n];
            n--;
        }
    }
};

// append at end then sort
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)    nums1[m+i]=nums2[i];
        sort(nums1.begin(),nums1.end());
    }
};