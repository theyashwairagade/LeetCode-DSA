class Solution {
public:
    int largestInteger(int n) {
        priority_queue<int> oddHeap, evenHeap;
        stack<int> stk;
        while(n)
        {
            int rem=n%10;
            n/=10;
            stk.push(rem);
            if(rem%2)   oddHeap.push(rem);
            else    evenHeap.push(rem);
        }
        n=0;
        while(!stk.empty())
        {
            n*=10;
            int rem=stk.top();
            if(rem%2)   n+=oddHeap.top(),oddHeap.pop();
            else    n+=evenHeap.top(),evenHeap.pop();
            stk.pop();
        }
        return n;
    }
};