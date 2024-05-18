class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> myMap;
        for(int number: nums)
            myMap[number]++;
        for(auto it: myMap)
            if(it.second%2) return false;
        return true;
    }
};