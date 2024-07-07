class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();

        for(int i=1; i+1<n; i++)
            if(colors[i-1]!=colors[i] && colors[i]!=colors[i+1])
                ans++;
        
        if(colors[n-1]!=colors[0] && colors[0]!= colors[1])
            ans++;
        if(colors[n-2]!=colors[n-1] && colors[n-1]!=colors[0])
            ans++;
        return ans;
    }
};