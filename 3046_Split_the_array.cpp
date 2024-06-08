class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int,int> mp;
        for(int number: nums)   mp[number]++;
        for(auto pair: mp)  if(mp[pair.first]>2)  return false;
        return true;
    }
}; 