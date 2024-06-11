class Solution {
public:
    int minimumChairs(string s) {
        int ans=0, count=0;
        for(char &c: s)
        {
            if(c=='E')
                count++;
            else
                count--;
            ans=max(ans,count);
        }
        return ans;
    }
};