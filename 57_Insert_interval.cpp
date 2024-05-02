class Solution {
public:
    bool isBetween(const vector<int>interval,int index)
    {
        if(index>=interval[0] && index<=interval[1])    return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(!n)  return {newInterval};
        // for(auto &vec:intervals)
        bool added=false;
        for(int i=0;i<intervals.size();i++)
        {
            if(isBetween(intervals[i],newInterval[0]) || isBetween(intervals[i],newInterval[0]))
            {
                intervals[i][0]=min(intervals[i][0],newInterval[0]);
                intervals[i][1]=max(intervals[i][1],newInterval[1]);
                added=true;
                break;
            }
            if(intervals[i][0]>newInterval[0])
            {   
                intervals.insert(intervals.begin()+i,newInterval);
                added=true;
                break;
            }
        }
        if(!added)
        {
            intervals.push_back(newInterval);
            return intervals;
        }  
        // return intervals;
        vector<vector<int>> ans;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
            if(intervals[i][0]<=end)
                start=min(start,intervals[i][0]),end=max(end,intervals[i][1]);
            else
            {
                ans.push_back({start,end});
                start=intervals[i][0], end=intervals[i][1];
            }
        ans.push_back({start,end});
        return ans;
    }
};