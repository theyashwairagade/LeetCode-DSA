class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        int dan=0,bob=0;
        for(auto i:possible)
            if(i)   bob++;
            else    bob--;
        for(int i=0;i<n-1;i++)
        {
            int val=possible[i];
            if(val)     dan++,bob--;
            else        dan--,bob++;
            if(dan>bob) return i+1;
        }
        return -1;
    }
};