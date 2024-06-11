struct Compare {
    bool operator()(const pair<char, int>& p1, const pair<char, int>& p2) {
        if (p1.first == p2.first) {
            // If characters are the same, compare integers in descending order
            return p1.second < p2.second;
        }
        // Otherwise, compare characters in ascending order
        return p1.first > p2.first;
    }
};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> heap;
        int n=s.size();
        vector<int> remove;
        for(int i=0; i<n;i++)
            if(s[i]!='*')
                heap.push({s[i],i});
            else
            {
                remove.push_back(heap.top().second);
                remove.push_back(i);
                heap.pop();
            }
        sort(remove.begin(), remove.end(),greater<int>());
        for(auto &i: remove)
            s.erase(i,1);
        return s;
    }
};