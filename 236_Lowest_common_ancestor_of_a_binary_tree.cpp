// Time complexity of O(n) and space complexity of O(n)
// Finding path of each node and storing in vector and then comparing both vectors
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* key, vector<TreeNode*> &vec)
    {
        if(!root)   return false;
        if(root==key)
        {
            vec.push_back(root);
            return true;
        }
        if(findPath(root->left,key,vec)||findPath(root->right,key,vec))
        {
            vec.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathOfP, pathOfQ;
        findPath(root,p,pathOfP);
        findPath(root,q,pathOfQ);

        reverse(pathOfP.begin(),pathOfP.end());
        reverse(pathOfQ.begin(),pathOfQ.end());

        int maxSize=min(pathOfP.size(),pathOfQ.size());
        for(int i=0;i<maxSize;i++)
        {
            if(pathOfP[i]!=pathOfQ[i]) return pathOfP[i-1];
        }
        return pathOfP[maxSize-1];
    }
};


// Time complexity O(n) space complexity O(1)
// See striver video
// Favorite try below by own
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return NULL;
        if(root==p || root==q)  return root;

        TreeNode* fromLeft=lowestCommonAncestor(root->left,p,q);
        TreeNode* fromRight=lowestCommonAncestor(root->right,p,q);

        if(fromLeft && fromRight)   return root;
        if(fromLeft)    return fromLeft;
        if(fromRight)   return fromRight;
        return NULL;
    }
};