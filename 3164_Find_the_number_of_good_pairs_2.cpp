class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> mp;
        for(auto &j: nums2)
            mp[j*k]++;
        
        long long ans=0;
        for(auto &i: nums1)
        {
            if(i%k)
                continue;
            int root=sqrt(i);
            for(int j=1; j<=root; j++)
            {
                if(i%j)
                    continue;
                ans+=mp[j];
                if(j != i/j)
                    ans+=mp[i/j];
            }
        }
        return ans;
    }
};