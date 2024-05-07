class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool shipped(vector<int> &weights, int &deadline, int &capacity)
    {
        int days=1, current=0;
        for(const auto &weight: weights)
            if(weight>capacity)
                return false;
            else if(current+weight<=capacity)
                current+=weight;
            else
                current=weight,days++;
        return days<=deadline;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=1, end=0;
        for(const auto &weight: weights)
            end+=weight;
        
        while(start<end)
        {
            int capacity=findMid(start,end);
            if(shipped(weights,days,capacity))
                end=capacity;
            else
                start=capacity+1;
        }
        return start;
    }
};