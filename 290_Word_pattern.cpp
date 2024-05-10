class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int start=0, i=0;
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        for(;i<pattern.size() && start<s.size();i++)
        {
            int len=0;
            while(start+len<s.size() && s[start+len]!=' ')    len++;
            string str=s.substr(start,len);
            char c=pattern[i];
            if(!mp.count(c) && !mp2.count(str))   mp[c]=str,mp2[str]=c;
            else    if(mp[c]!=str || mp2[str]!=c)  return false;
            start+=len+1;
        }
        if(start<s.size()|| i<pattern.size()) return false;
        for(auto pr:mp) cout<<pr.first<<" "<<pr.second<<endl;
        return true;
    }
};