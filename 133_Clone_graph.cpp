class Solution {
    void solve(unordered_map<int, Node*> &mp, Node* node){
        int val = node->val;
        if(mp.find(val)!=mp.end())
            return;

        mp[val] = new Node(val);
        for(auto &i: node->neighbors)
        {
            solve(mp, i);
            mp[val]->neighbors.push_back(mp[i->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        unordered_map<int, Node*> mp;
        solve(mp, node);
        return mp[1];
    }
};