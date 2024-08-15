typedef long long ll;
class Solution {
public:
    //SLIDING WINDOW: GOOD QUESTION
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        multiset<ll> st1, st2;
        ll curr= nums[0]; //we need to include this always
        k--;

        //sum of all elements from index 1 to dist+1
        for(int i=1;i<=dist+1;i++)
        {
            curr+=nums[i];
            st1.insert(nums[i]);
        }
        //now removing the larger numbers from last of the set to get k elements only
        while(st1.size()>k)
        {
            curr-= *st1.rbegin();
            st2.insert(*st1.rbegin());
            st1.erase(st1.find(*st1.rbegin()));
        }

        ll ans= curr;
        //now we will shift our window of size 'dist' to one step forward in each step, so we need to delete the nums[i-dist-1] from our set
        for(int i=dist+2;i<n;i++)
        {
            //removing the starting element of the prev. window
            if(st1.find(nums[i-dist-1]) != st1.end())
            {
                curr-= nums[i-dist-1];
                st1.erase(st1.find(nums[i-dist-1]));
            }
            else
            {
                st2.erase(st2.find(nums[i-dist-1]));
            }

            //adding current element into our set
            if(nums[i] < *st1.rbegin())
            {
                curr+= nums[i];
                st1.insert(nums[i]);
            }
            else
            {
                st2.insert(nums[i]);
            }

            //we want our set 1 i.e. st1 to have (k-1) elements exactly
            while(st1.size()<k) //if size is less than insert smaller elements from second set
            {
                curr+= *st2.begin();
                st1.insert(*st2.begin());
                st2.erase(st2.find(*st2.begin()));
            }
            while(st1.size()>k) //if size is large than remove large elements from set 1 and insert them into set 2
            {
                curr-= *st1.rbegin();
                st2.insert(*st1.rbegin());
                st1.erase(st1.find(*st1.rbegin()));
            }
            
            ans= min(ans, curr);
        }
        return ans;
    }
};