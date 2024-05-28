// Using hashmap and ordered set in time complexity of O(nlogn) and space complexity of n
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> mp;
        vector<long long int> ans;
        set<pair<long long,int>,greater<pair<long long, int>>> st;
        int n=nums.size();
        for(int i=0;i<n;i++)// n operation
        {
            int element=nums[i];
            pair<long long,int> pr={mp[element],element};
            if(st.find(pr)!=st.end())  st.erase(pr);// log n operation 
            mp[element]+=freq[i];
            pr={mp[element],element};
            st.insert(pr);// log n
            ans.push_back(st.begin()->first);
        }
        return ans;
    }
};