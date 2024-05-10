class Solution {
public:
    void dfs(vector<vector<int>>& image, int &n, int &m, int sr,int sc, int &color)
    {
        int current= image[sr][sc];
        image[sr][sc]=color;
        if(sr>0 && image[sr-1][sc]==current)
            dfs(image, n, m, sr-1, sc, color);
        if(sc>0 && image[sr][sc-1]==current)
            dfs(image, n, m, sr, sc-1, color);
        if(sr+1<n && image[sr+1][sc]==current)
            dfs(image, n, m, sr+1, sc, color);
        if(sc+1<m && image[sr][sc+1]==current)
            dfs(image, n, m, sr, sc+1, color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int n= image.size(), m=image[0].size();
        dfs(image, n, m, sr, sc, color);
        return image;
    }
};