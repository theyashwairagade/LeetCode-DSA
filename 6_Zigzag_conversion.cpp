class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows>=n || numRows==1)  return s;
        string ans="";
        for(int i=0;i<n;i+=2*(numRows-1))   ans+=s[i];
        for(int i=1;i<numRows-1;i++)
        {
            int j=i;
            ans+=s[j];
            while(j<n)
            {
                j+=2*(numRows-i-1);
                if(j>=n)    break;
                ans+=s[j];
                j+=2*i;
                if(j>=n)    break;
                ans+=s[j];
            }
        }
        for(int i=numRows-1;i<n;i+=2*(numRows-1))   ans+=s[i];
        return ans;
    }
};