class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words[0].size();
        int windowSize=words.size()*n;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int left=i, right=i;
            int want=words.size();
            unordered_map<string,int> mp;
            for(string str:words)   mp[str]++;
            while(right<s.size())
            {
                while(right<s.size() && right<left+windowSize)
                {
                    mp[s.substr(right,n)]--;
                    if(mp[s.substr(right,n)]>=0)    want--;
                    right+=n;
                }
                if(want==0) ans.push_back(left);
                while(right<s.size() && right>=left+windowSize)
                {
                    mp[s.substr(left,n)]++;
                    if(mp[s.substr(left,n)]>0)  want++;
                    left+=n;
                }
            }
        }
        return ans;
    }
};
