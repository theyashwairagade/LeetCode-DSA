// Using set as min heap with time complexity as (n*log(n)+m*k*log(n))= (m*k) and space complexity as (n+m)
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int long long sum=0;
        int n=nums.size();
        set<pair<int,int>> st; //It is working as min heap
        
        for(int i=0;i<n;i++)
        {
            st.insert({nums[i],i}); //log(n)
            sum+=nums[i]; //1
        }
        vector<long long> ans;
        for(auto q:queries)
        {
            int index=q[0],k=q[1];
            sum-=nums[index];
            nums[index]=0; //Marking it to zero to reduce one if condition

            while(st.size() && k)
            {
                auto [element,index]=*st.begin();
                st.erase({element,index}); // logn
                if(nums[index])
                {
                    sum-=nums[index];
                    nums[index]=0;
                    k--;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};