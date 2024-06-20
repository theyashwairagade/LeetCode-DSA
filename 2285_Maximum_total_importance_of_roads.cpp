// class Solution {
// public:
//     long long maximumImportance(int n, vector<vector<int>>& roads) {
//         unordered_map<int, long long> mp;
//         for(auto &road: roads)
//             mp[road[0]]++,
//             mp[road[1]]++;
        
//         vector<long long> vec;
//         for(auto &pr: mp)
//             vec.push_back(pr.second);
        
//         while(vec.size()!=n)
//             vec.push_back(0);
        
//         sort(vec.begin(), vec.end());
//         long long ans= 0;
//         for(int i=1; i<=n; i++)
//             ans+= i*vec[i-1];
        
//         return ans;
//     }
// };





// Optimizing further
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> vec(n,0);
        for(auto &road: roads)
            vec[road[0]]++,
            vec[road[1]]++;
        sort(vec.begin(), vec.end());
        
        long long ans= 0;
        for(int i=1; i<=n; i++)
            ans+= i*vec[i-1];
        
        return ans;
    }
};