// class Solution {
//     void storeNodeAndParent(unordered_map<int, pair<TreeNode*, TreeNode*>> &mp, TreeNode* root, TreeNode* parent = NULL){
//         if(!root)
//             return;
//         mp[root->val]= {root, parent};
//         storeNodeAndParent(mp, root->left, root);
//         storeNodeAndParent(mp, root->right, root);
//     }
//     void removeNodeFromParent(TreeNode* node, TreeNode* parent){
//         if(!parent)
//             return;
//         if(parent->left == node)
//             parent->left = NULL;
//         if(parent->right == node)
//             parent->right = NULL;
//     }
//     void removeNodeFromAns(TreeNode* node, vector<TreeNode*> &ans){
//         auto it = find(ans.begin(), ans.end(), node);

//         if (it != ans.end()) 
//             ans.erase(it);
//     }
//     void addNodeChildrenInAns(TreeNode* node, vector<TreeNode*> &ans){
//         if(node->left)
//             ans.push_back(node->left);
//         if(node->right)
//             ans.push_back(node->right);
//     }
// public:
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         // To store node, parent
//         unordered_map<int, pair<TreeNode*, TreeNode*>> mp;

//         storeNodeAndParent(mp, root);

//         vector<TreeNode*> ans;
//         if(root)
//             ans.push_back(root);

//         for(auto &del: to_delete){
//             auto entry = mp[del];
//             // 1st is itself 2nd is parent

//             removeNodeFromParent(entry.first, entry.second);
//             removeNodeFromAns(entry.first, ans);
//             addNodeChildrenInAns(entry.first, ans);
//         }

//         return ans;
//     }
// };





// Optimizing by using unordered_set
// class Solution {
//     void storeNodeAndParent(unordered_map<int, pair<TreeNode*, TreeNode*>> &mp, TreeNode* root, TreeNode* parent = NULL){
//         if(!root)
//             return;
//         mp[root->val]= {root, parent};
//         storeNodeAndParent(mp, root->left, root);
//         storeNodeAndParent(mp, root->right, root);
//     }
//     void removeNodeFromParent(TreeNode* node, TreeNode* parent){
//         if(!parent)
//             return;
//         if(parent->left == node)
//             parent->left = NULL;
//         if(parent->right == node)
//             parent->right = NULL;
//     }
//     void removeNodeFromRoots(TreeNode* node, unordered_set<TreeNode*> &roots){
//         if(roots.find(node)!=roots.end())
//             roots.erase(node);
//     }
//     void addNodeChildrenInRoots(TreeNode* node, unordered_set<TreeNode*> &roots){
//         if(node->left)
//             roots.insert(node->left);
//         if(node->right)
//             roots.insert(node->right);
//     }
// public:
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         // To store node, parent
//         unordered_map<int, pair<TreeNode*, TreeNode*>> mp;

//         storeNodeAndParent(mp, root);

//         unordered_set<TreeNode*> roots;
//         if(root)
//             roots.insert(root);

//         for(auto &del: to_delete){
//             auto entry = mp[del];
//             // 1st is itself 2nd is parent

//             removeNodeFromParent(entry.first, entry.second);
//             removeNodeFromRoots(entry.first, roots);
//             addNodeChildrenInRoots(entry.first, roots);
//         }

//         vector<TreeNode*> ans;
//         for(auto &i: roots)
//             ans.push_back(i);
//         return ans;
//     }
// };





// Most optimized code
class Solution {
    void storeNodeAndParent(unordered_map<int, pair<TreeNode*, TreeNode*>> &mp, TreeNode* root, TreeNode* parent = NULL){
        if(!root)
            return;
        mp[root->val]= {root, parent};
        storeNodeAndParent(mp, root->left, root);
        storeNodeAndParent(mp, root->right, root);
    }
    void removeNodeFromParent(TreeNode* node, TreeNode* parent){
        if(!parent)
            return;
        if(parent->left == node)
            parent->left = NULL;
        if(parent->right == node)
            parent->right = NULL;
    }
    void removeNodeFromRoots(TreeNode* node, unordered_set<TreeNode*> &roots){
        if(roots.find(node)!=roots.end())
            roots.erase(node);
    }
    void addNodeChildrenInRoots(TreeNode* node, unordered_set<TreeNode*> &roots){
        if(node->left)
            roots.insert(node->left);
        if(node->right)
            roots.insert(node->right);
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // To store node, parent
        unordered_map<int, pair<TreeNode*, TreeNode*>> mp;

        storeNodeAndParent(mp, root);

        unordered_set<TreeNode*> roots;
        if(root)
            roots.insert(root);

        for(auto &del: to_delete){
            auto entry = mp[del];
            // 1st is itself 2nd is parent

            removeNodeFromParent(entry.first, entry.second);
            removeNodeFromRoots(entry.first, roots);
            addNodeChildrenInRoots(entry.first, roots);
        }

        vector<TreeNode*> ans;
        for(auto &i: roots)
            ans.push_back(i);
        return ans;
    }
};





// Try code of aryan mittal too