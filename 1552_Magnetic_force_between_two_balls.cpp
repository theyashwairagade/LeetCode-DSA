class Solution {
    int solve(vector<int> &position, int m)
    {
        int ans = 1, prev = position[0];
        for(int &i: position)
            if(i - prev >= m)
                ans++,
                prev = i;
        return ans;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0, right = position.back() - position.front();
        while (left < right) {
            int mid = right - (right - left) / 2;
            if(solve(position, mid) >= m)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};