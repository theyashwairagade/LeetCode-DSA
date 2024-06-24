class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        int n= s2.size(), m= s1.size();
        if(n<m)
            return {};
        
        vector<int> want(26), have(26), ans;        
        for(int i=0; i<m; i++)
            want[s1[i]-'a']++,
            have[s2[i]-'a']++;

        int matches = 0;
        for(int i=0; i<26; i++)
            if(want[i]==have[i])
                matches++;
        
        int left =0;
        for(int right = m; right<n; right++, left++)
        {
            if(matches == 26)
                ans.push_back(left);
            
            have[s2[right]-'a']++;
            if(have[s2[right]-'a'] == want[s2[right]-'a'])
                matches++;
            else if(have[s2[right]-'a']-1 == want[s2[right]-'a'])
                matches--;
            
            have[s2[left]-'a']--;
            if(have[s2[left]-'a'] == want[s2[left]-'a'])
                matches++;
            else if(have[s2[left]-'a'] +1 == want[s2[left]-'a'])
                matches--;
        }
        if(matches == 26)
            ans.push_back(left);
        return ans;
    }
};