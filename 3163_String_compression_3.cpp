class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int count=1, n=word.size();
        for(int i=1; i<n; i++)
        {
            if(word[i]==word[i-1])
            {
                count++;
                if(count==9)
                    ans+=to_string(count)+word[i],
                    count=0;
            }else{
                if(count)
                    ans+=to_string(count)+word[i-1];
                count=1;
            }
        }
        if(count)
            ans+=to_string(count)+word[n-1];
        return ans;
    }
};