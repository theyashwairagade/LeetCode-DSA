class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> maxHeap;
        long long sum = 0;
        for(auto &i: target)
            maxHeap.push(i),
            sum+= i;
        
        while(maxHeap.top()!=1){
            int temp = maxHeap.top();
            maxHeap.pop();
            long long diff = sum-temp;
            if(diff==1)
                return true;
            if(diff>temp || !diff || temp%diff == 0)
                return false;
            temp%=diff;
            maxHeap.push(temp);
            sum= diff+temp;
        }
        return true;
    }
};