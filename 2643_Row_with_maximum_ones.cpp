class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n= mat.size(),index=0, maxOnes=0;
        for(int i=0;i<n;i++)
        {
            int ones=0;
            for(const int &binary: mat[i])
                if(binary)  ones++;
            if(ones>maxOnes)
                index=i,
                maxOnes=ones;
        }
        return {index, maxOnes};
    }
};