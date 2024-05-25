class Solution {
    private:
    int areaOfLargestRectangleInHistogram(vector<int>&heights)
    {
        int n=heights.size();
        stack<int>stk;

        int ans=0;
        for(int i=0;i<=n;++i)
        {
            while(!stk.empty() and (i==n || heights[stk.top()]>=heights[i]))
            {
                int height=heights[stk.top()];
                stk.pop();
                
                int width= i;
                if(!stk.empty()) 
                    width=i-stk.top()-1;

                ans=max(ans,height*width);
            }
            stk.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size(), m=matrix[0].size();
        vector<int>heights(m,0);

        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                if(matrix[i][j]=='1') 
                    heights[j]++;
                else 
                    heights[j]=0;
            
            ans=max(ans,areaOfLargestRectangleInHistogram(heights));
        }
        return ans;
    }
};