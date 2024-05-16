class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0,count=0;
        for(char ch: s)
        {
            if(ch=='R') count++;
            else if(ch=='L')    count--;
            if(count==0)    ans++;
        }
        return ans;
    }
};