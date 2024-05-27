// time complexity nlogn and space complexity is n
class Solution {
public:
    string minimizeStringValue(string s) {
        set<pair<int,char>> st;
        for(int i=0;i<26;i++)  st.insert({0,char(i+97)});
        
        for(char ch:s)
        {
            if(ch=='?') continue;
            auto it = find_if(st.begin(), st.end(), [&ch](const pair<int, char>& p) {
                return p.second == ch;
            });
            st.insert({it->first+1,ch});
            st.erase(it);
        }

        string temp="";
        for(char ch:s)
        {
            if(ch!='?') continue;
            auto bg=st.begin();
            temp+=bg->second;
            st.insert({bg->first+1,bg->second});
            st.erase(st.begin());
        }
        sort(temp.begin(),temp.end());

        int index=0;
        for(char &ch:s)
        {
            if(ch!='?') continue;
            ch=temp[index++];
        }
        return s;
    }
};