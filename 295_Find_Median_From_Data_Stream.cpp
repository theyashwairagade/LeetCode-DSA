class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int n;
    void normalizeTop(){
        if(maxHeap.size() && minHeap.size() && maxHeap.top()>minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    void normalizeSize(){
        if(n%2 == 0)
            while(maxHeap.size() != minHeap.size()){
                if(maxHeap.size() > minHeap.size()){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }else{
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        else
            while(maxHeap.size()-1 != minHeap.size()){
                if((maxHeap.size()-1 > minHeap.size())){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }else{
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
    }
public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        maxHeap.push(num);
        normalizeTop();
        normalizeSize();
    }
    
    double findMedian() {
        if(n%2)
            return maxHeap.top();
        return ((double) maxHeap.top() + minHeap.top())/2;
    }
};





// Optimization
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHeap.size() && num<=maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        if(maxHeap.size() > minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > maxHeap.size()+1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        if(maxHeap.size() == minHeap.size())
            return ((double) maxHeap.top() + minHeap.top())/2;

        return minHeap.top();
    }
};