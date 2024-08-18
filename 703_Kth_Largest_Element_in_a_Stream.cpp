class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int inputK, vector<int>& nums) {
        k = inputK;
        for(auto & i: nums){
            minHeap.push(i);
            if(minHeap.size()>k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
            if(minHeap.size()>k)
                minHeap.pop();
        return minHeap.top();
    }
};