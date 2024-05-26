class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        int l1=str1.size(),l2=str2.size();
        if(l1>l2)   return false;
        for(int i=0;i<l1;i++)
            if(str1[i]!=str2[i])    return false;
        for(int i=0;i<l1;i++)
            if(str1[l1-1-i]!=str2[l2-1-i])   return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int length=words.size();
        int ans=0;
        for(int i=0;i<length;i++)
            for(int j=i+1;j<length;j++)
                if(isPrefixAndSuffix(words[i],words[j]))    ans++;
        return ans;
    }
};