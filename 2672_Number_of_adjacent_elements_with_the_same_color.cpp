class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int length=queries.size();
        if(length<2)    return vector<int>(length,0);

        vector<int> ans;
        vector<int> nums(n,0);

        int index=0, color=1;
        int currentSize=0;
        for(auto query: queries)
        {
            int queryIndex=query[index];
            bool notFirstElement=(queryIndex>0);
            bool notLastElement=(queryIndex < n - 1);
            if(nums[queryIndex]!=0)
            {
                if(notFirstElement &&(nums[queryIndex]==nums[queryIndex-1]))
                    currentSize--;
                if (notLastElement && nums[queryIndex] == nums[queryIndex + 1])
                    currentSize--;
            }
            nums[queryIndex]=query[color];
            
            if(nums[queryIndex]!=0)
            {
                if (notFirstElement && nums[queryIndex] == nums[queryIndex - 1])
                    currentSize++;
                if (notLastElement && nums[queryIndex] == nums[queryIndex + 1])
                    currentSize++;
            }
            ans.push_back(currentSize);
        }
        return ans;
    }
};