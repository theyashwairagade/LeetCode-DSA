class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        map<int, int> mp;
        int myMin = INT_MAX;
        for(auto &i: nums)
            mp[i]++,
            myMin = min(myMin, i);
        
        for(auto &pr: mp)
            if(pr.first%myMin < myMin && pr.first%myMin)
        for(auto &i: nums)
            if(i%myMin)
                myMin = i%myMin;
        
        int val = mp.begin()->first;
        int valFor = mp.begin()->second;
        if(val!=myMin)
            return 1;
        return (valFor%2) ? valFor/2+1 : valFor/2;
    }
};