class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int length=costs.size();
        int cost=0;
        vector<int> difference, index;
        for(vector<int> vec: costs) difference.push_back(abs(vec[0]-vec[1]));
        for(int i=0;i<length;i++)   index.push_back(i);

        auto comperator=[&difference](int a,int b){
            return difference[a]<difference[b];
        };
        sort(index.begin(),index.end(),comperator);
        int A=0;
        for(int i=length-1;i>=0;i--)
        {
            int currentIndex=index[i];
            int a=costs[currentIndex][0], b=costs[currentIndex][1];
            int minCost=min(a,b);
            if(minCost==a)  A++;
            else    A--;
            cost+=minCost;
            if(A==i)
            {
                A--;
                while(A>=0)
                    cost+=costs[index[A--]][1];
                break;
            }
            if(A==-i)
            {
                A++;
                while(A<=0)
                {
                    cost+=costs[index[-A]][0];
                    A++;
                } 
                break;
            }
        }
        return cost;
    }
};