class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0, end=0;
        for(auto &meeting:meetings)
        {
            int start=meeting[0], tempEnd=meeting[1];
            if(end<start)
                ans+=(start-end-1);
            end=max(end,tempEnd);
        }
        ans+=(days-end);
        return ans;
    }
};