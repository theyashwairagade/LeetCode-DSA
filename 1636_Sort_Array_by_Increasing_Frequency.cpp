class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &num: nums)
            mp[num]++;
        map<int, vector<int>> finalMp;
        for(auto &pr: mp)
            finalMp[pr.second].push_back(pr.first);
        for(auto &pr: finalMp)
            sort(pr.second.begin(), pr.second.end(), greater<int> ());
        vector<int> ans;
        for(auto &pr: finalMp)
            for(auto &val: pr.second)
                for(int i=0; i<pr.first; i++)
                    ans.push_back(val);
        return ans;
    }
};