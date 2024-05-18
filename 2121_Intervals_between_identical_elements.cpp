class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int,vector<int>> mapping;
        int length=arr.size();
        for(int i=0;i<length;i++)   mapping[arr[i]].push_back(i);

        vector<long long> ans(length);
        
        for(auto pair: mapping)
        {
            long long int sum=0;
            for(int number: pair.second)    sum+=number;

            long long int prefixSum=0;

            int indexL=pair.second.size();
            for(int i=0;i<indexL;i++)
            {
                int index=pair.second[i];
                ans[index] = static_cast<long long>(index) * i - prefixSum + (sum - prefixSum - index) - (indexL - static_cast<long long>(i) - 1) * index;
                prefixSum += static_cast<long long>(index);
            }
        }
        
        return ans;
    }
};