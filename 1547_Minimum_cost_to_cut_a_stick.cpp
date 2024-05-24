// Brutte force will give tle
class Solution {
public:
    int solve(vector<int> &cuts, int startingIndex, int endingIndex, int startingLen, int endingLen)
    {
        if(startingIndex>endingIndex)
            return 0;
        int currentCost=endingLen-startingLen;
        if(startingIndex==endingIndex)
            return currentCost;
        int adding=1e7;
        for(int i=startingIndex; i<=endingIndex; i++)
        {
            int left=solve(cuts, startingIndex, i-1, startingLen, cuts[i]);
            int right=solve(cuts, i+1, endingIndex, cuts[i], endingLen);
            adding=min(adding, left+right);
        }
        return currentCost+adding;
    }
    int minCost(int length, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int startingLen=0, endingLen=length;
        int n=cuts.size();
        int startingIndex=0, endingIndex=n-1;
        return solve(cuts, startingIndex, endingIndex, startingLen, endingLen);
    }
};





// To solve overlapping subproblems in constant time using memorization buy this will give mle
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &cuts, int startingIndex, int endingIndex, int startingLen, int endingLen)
    {
        if(startingIndex>endingIndex)
            return 0;
        if(dp[startingLen][endingLen]!=-1)
            return dp[startingLen][endingLen];
        int currentCost=endingLen-startingLen;
        if(startingIndex==endingIndex)
            return dp[startingLen][endingLen]= currentCost;
        int adding=1e7;
        for(int i=startingIndex; i<=endingIndex; i++)
        {
            int left=solve(dp, cuts, startingIndex, i-1, startingLen, cuts[i]);
            int right=solve(dp, cuts, i+1, endingIndex, cuts[i], endingLen);
            adding=min(adding, left+right);
        }
        return dp[startingLen][endingLen]= currentCost+adding;
    }
    int minCost(int length, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int startingLen=0, endingLen=length;
        int n=cuts.size();
        int startingIndex=0, endingIndex=n-1;
        vector<vector<int>> dp(length+1, vector<int> (length+1,-1));
        return solve(dp, cuts, startingIndex, endingIndex, startingLen, endingLen);
    }
};





// Let's start striver's approach will give tle
class Solution {
public:
    int solve(vector<int> &cuts, int start, int end)
    {
        if(start>end)
            return 0;
        int cost= cuts[end+1]-cuts[start-1];
        if(start==end)
            return cost;
        
        int costOfSolvingPartition= INT_MAX;
        for(int i=start; i<=end; i++)
        {
            int value=solve(cuts, start, i-1) + solve(cuts, i+1, end);
            costOfSolvingPartition=min(costOfSolvingPartition, value);
        }
        return cost+costOfSolvingPartition;
    }
    int minCost(int length, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(length);
        cuts.insert(cuts.begin(),0);
        return solve(cuts, 1, cuts.size()-2);
    }
};





// To solve overlapping subproblems in constant time perform memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &cuts, int start, int end)
    {
        if(start>end)
            return 0;
        if(dp[start-1][end-1]!=-1)
            return dp[start-1][end-1];

        int cost= cuts[end+1]-cuts[start-1];
        if(start==end)
            return dp[start-1][end-1]= cost;
        
        int costOfSolvingPartition= INT_MAX;
        for(int i=start; i<=end; i++)
        {
            int value=solve(dp, cuts, start, i-1) + solve(dp, cuts, i+1, end);
            costOfSolvingPartition=min(costOfSolvingPartition, value);
        }
        return dp[start-1][end-1]= cost+costOfSolvingPartition;
    }
    int minCost(int length, vector<int>& cuts) {
        int n=cuts.size();
        sort(cuts.begin(), cuts.end());

        cuts.push_back(length);
        cuts.insert(cuts.begin(),0);

        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(dp, cuts, 1, n);
    }
};