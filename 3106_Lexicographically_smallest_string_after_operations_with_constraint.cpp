class Solution {
public:
    string getSmallestString(string s, int k) {
        if(!k)  return s;
        int n=s.size();
        for(int i=0;k>0 && i<n;i++)
        {
            if(s[i]=='a')   continue;
            int maxReduction='z'-s[i];
            if(s[i]>'m' && k>maxReduction)
            {
                s[i]='a';
                k-=maxReduction;
                k--;
            }
            else
            {
                int minus=min(s[i]-'a',k);
                s[i]-=minus;
                k-=minus;                
            }
        }
        return s;
    }
};