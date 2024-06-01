// This approach fails at test case [[4,4],[9,10],[9,10],[3,8]]
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n=nums.size(), ans=0;
        sort(nums.begin(),nums.end());

        int endOfLine=nums[0][1];
        ans+=nums[0][0]-1;

        for(int i=1; i<n; i++)
            ans+=max(0, nums[i][0]-nums[i-1][1]-1),
            endOfLine= max(endOfLine, nums[i][1]);

        return endOfLine-ans;
    }
};





// Correcting mistake which was done above
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), prevEnd= nums[0][1];

        int ans=prevEnd-nums[0][0]+1;
        for(int i=1; i<n; i++)
        {
            int currentStart= nums[i][0], currentEnd= nums[i][1];
            if(prevEnd==currentStart)
                ans+= currentEnd-currentStart, 
                prevEnd= currentEnd;
            else if(prevEnd< currentStart)
                ans+= currentEnd-currentStart+1,
                prevEnd= currentEnd;
            else if(currentStart<prevEnd && prevEnd< currentEnd)
                ans+=currentEnd-prevEnd,
                prevEnd= currentEnd;
        }
        return ans;
    }
};





// Solving using set datastructure i.e. brutte force
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int endOfLine= nums[0][1];
        for(auto &car: nums)
            endOfLine=max(endOfLine,car[1]);

        unordered_set<int> points;
        for(int i=1; i<endOfLine; i++)
            points.insert(i);
        
        for(auto &car: nums)
        {
            for(int start= car[0], end= car[1]; start<=end; start++)
                points.erase(start);
        }
        return endOfLine-points.size();
    }
};





// Optimizing code with much more efficient logic
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> points;
        
        for(auto &car: nums)
            for(int start= car[0], end= car[1]; start<=end; start++)
                points.insert(start);
        return points.size();
    }
};





// Instead of unordered_set trying with unordered_map
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int endOfLine= nums[0][1];
        unordered_map<int, int> mp;

        for(auto &car: nums)
            mp[car[0]]=max(mp[car[0]], car[1]),
            endOfLine=max(endOfLine, car[1]);

        int pointer= 0, ans=0;
        for(int i=1; i<=endOfLine; i++)
        {
            pointer=max(pointer, mp[i]);
            if(i<=pointer)
                ans++;
            if(i==pointer)
                pointer=0;
        }
        return ans;
    }
};