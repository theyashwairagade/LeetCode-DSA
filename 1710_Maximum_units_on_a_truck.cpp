class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto sortByUnits = [this](const vector<int>& a, const vector<int>& b) {
            return a[1]>b[1];
        };

        sort(boxTypes.begin(), boxTypes.end(), sortByUnits);

        int n= boxTypes.size(), ans=0;
        for(int i=0; i<n && truckSize; i++)
        {
            int noOfBoxes= min(truckSize, boxTypes[i][0]);
            ans+=noOfBoxes*boxTypes[i][1];
            truckSize-=noOfBoxes;
        }
        
        return ans;
    }
};





// Due to less constrains we can apply bucket sort too
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> noOfBoxes(1001,0);
        for(auto &box:boxTypes)
            noOfBoxes[box[1]]+=box[0];
        
        int ans=0;
        for(int i=1000; i>0 && truckSize; i--)
        {
            int boxes=min(truckSize, noOfBoxes[i]);
            ans+=i*boxes;
            truckSize-=boxes;
        }
        return ans;
    }
};