class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int ind1 = s.size();
        int ind2 = t.size();
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,0));
        for(int i=0;i<=ind1;i++) dp[i][0]=0;
        for(int j=0;j<=ind2;j++) dp[0][j]=0;

        for(int i=1;i<=ind1;i++){
            for(int j=1;j<=ind2;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=ind1,j=ind2;
        string ans = "";
        while(i>0 and j>0){
            if(s[i-1]==t[j-1]){
                ans+=s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s[i-1];
                i--;
            }
            else{
                ans+=t[j-1];
                j--;
            }
        }
        while(i>0) {ans+=s[i-1];i--;}
        while(j>0) {ans+=t[j-1];j--;}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};