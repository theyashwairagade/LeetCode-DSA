class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> single, twice;
        int ans=0;
        for(auto &num: nums)
            if(single.find(num)!=single.end())
                ans^=num;
            else
                single.insert(num);
        return ans;
    }
};