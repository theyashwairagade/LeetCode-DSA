class Solution {
    int solve(int (&dp)[2][10][12][12][20][2], int &k, string & num, bool tight =1, int index = 0, int odd = 0, int even = 0, int rem = 0, bool leadingZeroes = true){
        if(index == num.size())
            return (!leadingZeroes && rem == 0 && odd == even);

        if(dp[tight][index][odd][even][rem][leadingZeroes] != -1)
            return dp[tight][index][odd][even][rem][leadingZeroes];

        int end = tight ? num[index]-'0' : 9,
            ans = leadingZeroes ? solve(dp, k, num,0,index+1,odd,even,rem,1) : 0;

        for(int dig = 0; dig<=end; dig++){
            bool newTight = (tight && (dig == num[index]-'0'));
            int newOdd = odd + (dig%2),
                newEven = even + ((!leadingZeroes || dig>0) && dig%2==0);

            if((leadingZeroes && dig != 0) || !leadingZeroes)
                ans = ans + solve(dp, k, num,newTight,index+1,newOdd,newEven, ((rem*10) + dig)%k, 0);
        }

        return dp[tight][index][odd][even][rem][leadingZeroes] = ans;
    }
public:

    int numberOfBeautifulIntegers(int low, int high, int k) {
        int dp[2][10][12][12][20][2];
        string lowerString = to_string(low-1);
        string higherString = to_string(high);

        memset(dp,-1,sizeof(dp));
        int forHigh = solve(dp, k, higherString);
        
        memset(dp,-1,sizeof(dp));
        int forLow = solve(dp, k, lowerString); 
        return forHigh-forLow;
    }
};