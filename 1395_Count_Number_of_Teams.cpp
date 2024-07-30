class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=2; i<n; i++)
            for(int j = 1; j<i; j++){
                if(rating[j]<rating[i])
                    // Search for lower
                    for(int k = 0; k<j; k++)
                        if(rating[k]<rating[j])
                            ans++;
                if(rating[j]>rating[i])
                    // Search for higher
                    for(int k = 0; k<j; k++)
                        if(rating[k]>rating[j])
                            ans++;
            }
        return ans;
    }
};





// Optimization Planning to start from middle
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> leftSmaller(n, 0), leftGreater(n, 0), rightSmaller(n, 0), rightGreater(n, 0);
        for(int i=0; i<n; i++){
            // For left
            for(int j=0; j<i; j++)
                if(rating[j]<rating[i])
                    leftSmaller[i]++;
                else if(rating[j]>rating[i])
                    leftGreater[i]++;
            // For right
            for(int j=i+1; j<n; j++)
                if(rating[j]<rating[i])
                    rightSmaller[i]++;
                else if(rating[j]>rating[i])
                    rightGreater[i]++;
        }
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += ((leftSmaller[i]*rightGreater[i]) + (leftGreater[i]*rightSmaller[i]));
        return ans;
    }
};





// Space optimization
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int leftSmaller = 0, leftGreater = 0, rightSmaller = 0, rightGreater = 0;
            // For left
            for(int j=0; j<i; j++)
                if(rating[j]<rating[i])
                    leftSmaller++;
                else if(rating[j]>rating[i])
                    leftGreater++;
            // For right
            for(int j=i+1; j<n; j++)
                if(rating[j]<rating[i])
                    rightSmaller++;
                else if(rating[j]>rating[i])
                    rightGreater++;
            ans += ((leftSmaller*rightGreater) + (leftGreater*rightSmaller));
        }
        return ans;
    }
};





// Can be optimized further as has unique ratings





// It has soln of dp , memonization, bottom up with parameters as (index, bool isAsc, currSizeOfSequence)