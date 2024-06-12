class Solution {
    int maxIndex(vector<int> &arr)
    {
        int ans=0, n=arr.size();
        for(int i=1; i<n; i++)
            if(arr[ans]<arr[i])
                ans=i;
        return ans;
    }
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        if(k>=n-1)
            return maxIndex(skills);
        
        deque<int> dq;
        for(int i=0; i<n; i++)
            dq.push_back(i);
        
        int count=0;
        int a, b;
        while(count<k)
        {
            a=dq.front();
            dq.pop_front();
            b=dq.front();
            dq.pop_front();
            if(skills[a]>skills[b])
                count++,
                dq.push_front(a),
                dq.push_back(b);
            else
                count=1,
                dq.push_front(b),
                dq.push_back(a),
                swap(a,b);
        }
        return a;
    }
};