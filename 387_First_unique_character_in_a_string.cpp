class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> myMap;
        for(char letter:s)  myMap[letter]++;
        for(int i=0;i<s.size();i++)
            if(myMap[s[i]]==1)  return i;
        return -1;
    }
};