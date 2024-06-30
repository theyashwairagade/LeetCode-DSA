// struct PairHash {
//     std::size_t operator()(const std::pair<int, int>& p) const {
//         return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
//         unordered_set<pair<int, int>, PairHash> st;

//         minHeap.push({nums1[0]+nums2[0], 0, 0});
//         st.insert({0,0});


//         vector<vector<int>> ans;
//         while(!minHeap.empty() && k--){
//             int i = minHeap.top()[1], j = minHeap.top()[2];
            
//             ans.push_back({nums1[i], nums2[j]});
//             st.insert({i,j});
//             minHeap.pop();
//             if(i+1<nums1.size() && st.find({i+1, j})==st.end())
//                 minHeap.push({nums1[i+1]+nums2[j], i+1, j}), 
//                 st.insert({i+1, j});
//             if(j+1<nums2.size() && st.find({i, j+1})==st.end())
//                 minHeap.push({nums1[i]+nums2[j+1], i, j+1}), 
//                 st.insert({i, j+1});
//         }
//         return ans;
//     }
// };





// optimizing so won't require unordered_set
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // sum, index of nums2

        for(int x : nums1)
            pq.push({x + nums2[0], 0});

        while(k-- && !pq.empty()) {
            int sum = pq.top().first,
                indexOfNums2 = pq.top().second; 

            ans.push_back({sum - nums2[indexOfNums2], nums2[indexOfNums2]});
            pq.pop();

            if(indexOfNums2 + 1 < nums2.size())
                pq.push({sum - nums2[indexOfNums2] + nums2[indexOfNums2 + 1], indexOfNums2 + 1});
        }

        return ans; // Return the k smallest pairs
    }
};