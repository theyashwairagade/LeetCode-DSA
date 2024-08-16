class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> mp(26, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;

        for(auto &word: words){
            minHeap.push(word.size());
            for(auto &c: word)
                mp[c-'a']++;
        }

        int odd = 0;
        for(auto &i: mp){
            if(i%2)
                i--,
                odd++;
            if(i)
                maxHeap.push(i);
        }

        int ans = 0;
        while(!minHeap.empty()){
            int want = minHeap.top();
            minHeap.pop();

            if(want%2 && odd)
                want--,
                odd--;
            
            while(want && maxHeap.size()){
                int tp = maxHeap.top();
                maxHeap.pop();
                int del = min(want, tp);

                want -= del;
                tp-= del;

                if(tp%2)
                    odd++,
                    tp--;
                if(tp)
                    maxHeap.push(tp);
            }
            if(!want)
                ans++;
            else
                return ans;
        }
        return ans;
    }
};