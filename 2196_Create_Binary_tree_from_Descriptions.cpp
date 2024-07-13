class Solution {
    TreeNode* findNode(int a, unordered_map<int, TreeNode*> &mp){
        if(mp.find(a)!=mp.end())
            return mp[a];
        return mp[a] = new TreeNode(a);
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> isChildren;

        for(auto &description: descriptions){
            auto parent = findNode(description[0], mp),
                 child = findNode(description[1], mp);
            bool isLeftChild = description[2];

            isChildren.insert(description[1]);
            if(isLeftChild)
                parent->left = child;
            else
                parent->right = child;
        }

        for(auto &pr: mp)
            if(isChildren.find(pr.first)==isChildren.end())
                return pr.second;
        return NULL;
    }
};