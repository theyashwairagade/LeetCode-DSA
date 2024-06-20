// Brutte by me with time complexity of O(n) and space complexity of O(n)
// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         unordered_map<int,int> mp;
//         for(auto &edge: edges)
//             mp[edge[0]]++,
//             mp[edge[1]]++;
//         for(auto &pr: mp)
//             if(pr.second==edges.size())
//                 return pr.first;
//         return -1;
//     }
// };





// Optimizing to time complexity of O(1) and space complexity of O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Logic in every edge ans is present either in start or end
        int a = edges[0][0], b = edges[0][1], c= edges[1][0], d = edges[1][1];
        if(a==c || a==d)
            return a;
        return b;
    }
};