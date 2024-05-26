class Solution {
public:
    int lastIndex(string s, char c)
    {
        int length=s.size();
        for(int i=length-1;i>=0;i--)   if(s[i]==c) return i;
        return 0;
    }
    string lastNonEmptyString(string s) {
        map<char,int> mapping;
        
        vector<pair<char,int>> vec;
        for(char character:s)   mapping[character]++;
        int highest=0;
        
        for(auto pair: mapping)
            if(pair.second>highest) highest=pair.second;
        
        for(auto pair: mapping)
            if(pair.second==highest)
                vec.push_back(make_pair(pair.first,lastIndex(s,pair.first)));
        
        sort(vec.begin(), vec.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });
        
        string ans="";
        for(auto pair: vec)
            ans+=pair.first;
        return ans;
    }
};