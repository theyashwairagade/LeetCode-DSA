class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples=0;
        for(auto &i: apple)
            apples+=i;
        
        sort(capacity.begin(), capacity.end());
        int n=capacity.size();
        
        int i;
        for(i=n-1; i>=0 && apples>0; i--)
            apples-=capacity[i];

        return n-i-1;
    }
};