class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool first = false, second = false;
        for(auto &i: arr)
            if(i%2)
            {
                if(first && second)
                    return true;
                if(first)
                    second=true;
                else
                    first=true;
            }else
                first = second  = false;
        return false;
    }
};