class Solution {
public:
    int countPalim(string s,int length, int left,int right)
    {   int ans=0;
        while(left>=0 && right<length && s[left]==s[right])
        {   ans++;
            left--;
            right++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans=0, length=s.size();
        for(int i=0;i<length;i++)
        {   ans+=countPalim(s,length,i,i);
            ans+=countPalim(s,length,i,i+1);
        }
        return ans;
    }
};