class Solution {
public:
    int valid(vector<vector<int>>& points, string &s, int len)
    {
        int count=0, n=s.size();
        unordered_map<char,bool> mp;
        for(int i=0; i<n; i++)
            if(abs(points[i][0])<=len && abs(points[i][1])<=len)
            {
                if(mp[s[i]])
                    return -1;
                else
                    count++,
                    mp[s[i]]=true;
            }
        return count;
    }
    int findMid(int &a, int &b)
        {return a+(b-a)/2;}
    bool compareSum(const std::vector<int>& a, const std::vector<int>& b) 
        {return (a[0] + a[1]) < (b[0] + b[1]);}
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int start=0, end=abs(points[0][0]);
        for(auto &vec: points)
            for(int &i: vec)
                end=max(end,abs(i));
        int ans=0;
        while(start+1<end)
        {
            int mid=findMid(start,end);
            if(valid(points, s, mid)==-1)
                end=mid-1;
            else
                start=mid;
        }
        return max(valid(points,s, start),valid(points,s,start+1));
    }
};