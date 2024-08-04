// Time complexity of O(N) and space complexity of O(N)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto &i: arr)
            mp[i]++;
        for(auto &i: target)
            if(--mp[i]<0)
                return false;
        return true;
    }
};






// // Time complexity of O(NlogN) and space complexity of O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        if(n!= arr.size())
            return false;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++)
            if(target[i]!=arr[i])
                return false;
        return true;
    }
};