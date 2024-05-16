class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<int> incoming(n,0);
            vector<int> outgoing(n,0);
    
            for(auto pair: trust)   incoming[pair[1]-1]++, outgoing[pair[0]-1]++;
    
            n--;
            for(int i=0;i<=n;i++)   if(incoming[i]==n && outgoing[i]==0)    return i+1;
            return -1;
        }
    };