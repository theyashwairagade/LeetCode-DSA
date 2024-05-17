class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int length=heights.size();
        if(ladders==0)
        {
            for(int i=1;i<length;i++)
            {   
                int difference=heights[i]-heights[i-1];
                if(difference<=0) continue;
                bricks-=difference;
                if(bricks<0)    return i-1;
            }
            return length-1;
        }
        priority_queue<int, vector<int>, greater<int>> laddering;
        laddering.push(0);
        for(int i=1;i<length;i++)
        {
            int difference=heights[i]-heights[i-1];
            if(difference<=0) continue;

            int tp=laddering.top();

            if(laddering.size()<ladders || difference>tp)
                laddering.push(difference);
            else    bricks-=difference;
            if(laddering.size()>ladders)
            {
                bricks-=laddering.top();
                laddering.pop();
            }
            if(bricks<0)    return i-1;
        }
        return length-1;
    }
};