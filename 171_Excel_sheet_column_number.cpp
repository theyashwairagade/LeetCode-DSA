class Solution {
public:
    int titleToNumber(string columnTitle) {
        unsigned int multiplier=1;
        int ans=0;
        for(int i=columnTitle.size()-1;i>=0;i--)
            ans+=((int(columnTitle[i])-64)*multiplier),
            multiplier*=26;
        return ans;
    }
};