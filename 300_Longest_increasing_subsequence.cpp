// Will give TLE
class Solution {
public:
    int solve(vector<int> &nums, int index, int prev)
    {
        if(index<0)
            return 0;
        int notTake=solve(nums,index-1, prev);
        int take=(nums[index]>=prev)?0:1+solve(nums, index-1, nums[index]);
        return max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=INT_MAX;
        return solve(nums, n-1, prev);
    }
};





// To solve overlapping subproblems in constant time do memorization
class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int index, int prevIndex)
    {
        if (index < 0)
            return 0;

        if (dp[index][prevIndex + 1] != -1)
            return dp[index][prevIndex + 1];

        int notTake = solve(dp, nums, index - 1, prevIndex);
        int take = 0;
        if (prevIndex == -1 || nums[index] < nums[prevIndex])
            take = 1 + solve(dp, nums, index - 1, index);

        return dp[index][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(dp, nums, n - 1, -1);
    }
};





// Tabulation





// Space optimization 1





// Space optimization 2





// This method is ratta
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        
        for(int current=0;current<n;current++)
            for(int prev=0; prev<current; prev++)
                if(nums[prev]<nums[current])
                    dp[current]=max(dp[current],1+dp[prev]);
        
        int ans=1;
        for(auto &i: dp)
            ans=max(ans,i);
        return ans;
    }
};





// Extra: To print longest increasing subsequence we are using backtracking
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), prev(n);
        
        for(int i=0;i<n;i++)
            prev[i]=i;
        
        for(int i=0;i<n;i++)
            for(int j=0; j<i; j++)
                if(nums[j]<nums[i] && 1+dp[j]>dp[i])
                {
                    prev[i]=j;
                    dp[i]=1+dp[j];
                }
        
        int ans=1;
        for(auto &i: dp)
            ans=max(ans,i);

        int maxIndex=0;
        for(int i=1;i<n;i++)
            if(dp[i]>dp[maxIndex])
                maxIndex=i;
        
        vector<int> ansVector;
        while(prev[maxIndex]!=maxIndex)
        {
            ansVector.push_back(nums[maxIndex]);
            maxIndex=prev[maxIndex];
        }
        ansVector.push_back(nums[maxIndex]);

        reverse(ansVector.begin(), ansVector.end());
        cout<<"Longest increasing subsequence is ";
        for(auto &i: ansVector)
            cout<<i<<" ";
        return ans;
    }
};





// This method is also ratta
// To optimize time complexity from O(n square) to O(nlogn) use binary search approach
class Solution {
public:
    int findMid(int a, int b)
        {return a+(b-a)/2;}
    int searchLowerBound(vector<int> &vec, int &searchingElement, int start, int end)
    {
        if(start==end)
            return start;
        int mid=findMid(start,end);
        if(vec[mid]==searchingElement)
            return mid;
        if(searchingElement>vec[mid])
            return searchLowerBound(vec, searchingElement, mid+1, end);
        return searchLowerBound(vec, searchingElement, start, mid);
    }
    int lowerBound(vector<int> &vec, int searchingElement)
    {
        int n=vec.size();
        return searchLowerBound(vec, searchingElement, 0, n-1);
    }
    void add(vector<int> &vec, int addingElement)
    {
        if(vec.empty() || vec.back()<addingElement)
        {
            vec.push_back(addingElement);
            return;
        }
        vec[lowerBound(vec,addingElement)]=addingElement;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;

        for(auto &i: nums)
            add(vec,i);
        
        return vec.size();
    }
};





// optimize stack space of lower bound function by converting recursive function to iterative function





// To simplify code using STL for lower bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;

        for(auto &i: nums)
            if(vec.empty() || vec.back()<i)
                vec.push_back(i);
            else
                *lower_bound(vec.begin(),vec.end(),i)=i;
        // Used * as it returns iterator
        return vec.size();
    }
};





// We can also prevent space used by changing data into original array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=0;

        for(auto &i: nums)
            if(!len || nums[len-1]<i)
                nums[len++]=i;
            else
                *lower_bound(nums.begin(),nums.begin()+len,i)=i;
        // Used * as it returns iterator
        return len;
    }
};