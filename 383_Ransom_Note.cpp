class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mapping;
        for(char character: magazine)
            mapping[character]++;
        for(char character: ransomNote)
            mapping[character]--;
        
        for(auto pair:mapping)  if(pair.second<0)   return false;
        return true;
    }
};