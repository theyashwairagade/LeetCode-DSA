class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty())  return "";
        unordered_map<char,int> dictionary;
        for(char c:t)   dictionary[c]++;
        int required=dictionary.size();
        int left=0,right=0,formed=0;
        unordered_map<char,int> windowCount;
        int ans[3]={-1,0,0};
        while(right<s.length())
        {
            char c=s[right];
            int count=windowCount[c]++;

            bool keyExistsInDictionary=(dictionary.find(c)!=dictionary.end());
            bool countMatch=(windowCount[c]==dictionary[c]);
            if(keyExistsInDictionary && countMatch) formed++;

            while(left<=right && formed==required)
            {
                c=s[left];

                bool noPreviousAnswer=ans[0]==-1;
                bool smallerNewAnswer=right-left+1<ans[0];
                if(noPreviousAnswer || smallerNewAnswer)
                {
                    ans[0]=right-left+1;
                    ans[1]=left;
                    ans[2]=right;
                }
                windowCount[c]--;
                
                bool keyExistsInDictionary=(dictionary.find(c)!=dictionary.end());
                bool lessCount=windowCount[c]<dictionary[c];
                if(keyExistsInDictionary && lessCount)  formed--;
                left++;
            }
            right++;
        }
        return ans[0]==-1?"":s.substr(ans[1],ans[0]);
    }
};