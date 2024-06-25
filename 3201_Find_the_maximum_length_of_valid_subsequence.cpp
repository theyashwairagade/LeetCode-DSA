class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int count=0;

        // counting even even
        for(auto &num: nums)
            if(!(num%2))
                count++;
        
        int ans = max(count , n-count); // checked for even even and odd odd

        // checking for odd even
        count = 0;
        bool lookingForOdd = true;
        for(auto &num: nums)
            if(num%2 && lookingForOdd)
                count++,
                lookingForOdd = false;
            else if(!(num%2) && !(lookingForOdd))
                count++,
                lookingForOdd = true;
        ans = max(ans, count);


        // checking for even odd
        count = 0;
        lookingForOdd = false;
        for(auto &num: nums)
            if(num%2 && lookingForOdd)
                count++,
                lookingForOdd = false;
            else if(!(num%2) && !(lookingForOdd))
                count++,
                lookingForOdd = true;
        ans = max(ans, count);
        return ans;
    }
};