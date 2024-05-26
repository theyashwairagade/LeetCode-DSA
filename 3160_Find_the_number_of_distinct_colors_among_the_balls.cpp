class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        unordered_map<int,int> balls;
        unordered_map<int,int> colors;

        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int ball=queries[i][0], color=queries[i][1];
            int ballColor=balls[ball];
            if(ballColor)
            {
                colors[ballColor]--;
                if(!colors[ballColor])
                    colors.erase(ballColor);
            }
            colors[color]++;
            balls[ball]=color;
            
            ans[i]=int(colors.size());
        }
        return ans;
    }
};