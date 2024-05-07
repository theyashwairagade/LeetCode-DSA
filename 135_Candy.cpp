// Greedy approach with time complexity as O(n) and space complexity as O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        if(len<2)   return len;
        vector<int> ans(len,1);

        // Forward Pass
        for(int i=1;i<len;i++)
            if(ratings[i]>ratings[i-1]) ans[i]=ans[i-1]+1;
        
        int sum=ans[len-1];
        // Backward Pass
        for(int i=len-1;i;i--)
        {
            if(ratings[i-1]>ratings[i]) ans[i-1]=max(ans[i-1],ans[i]+1);
            sum+=ans[i-1];
        }
        return sum;
    }
};