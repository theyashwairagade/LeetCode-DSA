class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count=0;
        for(auto &character: s)
            if(character==c)
                count++;

        long long ans=count;
        while(count--)
            ans+=count;
        
        return ans;
    }
};