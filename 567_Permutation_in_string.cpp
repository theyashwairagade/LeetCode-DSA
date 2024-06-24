// class Solution {
//     bool present(unordered_map<char,int> want, string str)
//     {
//         for(auto &c: str)
//             if(!want[c])
//                 return false;
//             else
//                 want[c]--;
//         return true;
//     }
// public:
//     bool checkInclusion(string s1, string s2) {
//         unordered_map<char, int> want;
//         for(char &c: s1)
//             want[c]++;
        
//         int n= s2.size(), m= s1.size();
//         for(int i=0; i<=n-m; i++)
//             if(present(want, s2.substr(i, m)))
//                 return true;
//         return false;
//     }
// };





// Optimizing using sliding window concept
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s2.size(), m= s1.size();
        if(n<m)
            return false;
        
        vector<int> want(26), have(26);        
        for(int i=0; i<m; i++)
            want[s1[i]-'a']++,
            have[s2[i]-'a']++;

        int matches = 0;
        for(int i=0; i<26; i++)
            if(want[i]==have[i])
                matches++;
        
        for(int right = m, left=0; right<n; right++, left++)
        {
            if(matches == 26)
                return true;
            
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
        return matches == 26;
    }
};