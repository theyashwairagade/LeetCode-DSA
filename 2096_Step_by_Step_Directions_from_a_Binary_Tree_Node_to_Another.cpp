class Solution {
    TreeNode* lowestCommonAncestor(TreeNode* root, int &p, int &q) {
        if(!root)   return NULL;
        if(root->val==p || root->val==q)  return root;

        TreeNode* fromLeft=lowestCommonAncestor(root->left,p,q);
        TreeNode* fromRight=lowestCommonAncestor(root->right,p,q);

        if(fromLeft && fromRight)   return root;
        if(fromLeft)    return fromLeft;
        if(fromRight)   return fromRight;
        return NULL;
    }
    bool findDirection(TreeNode* root, int &findVal, string &direction){
        if(!root)
            return false;
        if(root->val == findVal)
            return true;

        direction+= "L";
        if(findDirection(root->left, findVal, direction))
            return true;
        
        direction.back() = 'R';
        if(findDirection(root->right, findVal, direction))
            return true;
        
        direction.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto lca = lowestCommonAncestor(root, startValue, destValue);

        string temp = "";
        findDirection(lca, startValue, temp);

        string ans = string(temp.size(), 'U');
        temp = "";

        findDirection(lca, destValue, temp);
        return ans + temp;
    }
};





// Optimizing
class Solution {
    void findDirections(TreeNode* root, int &findVal1, int &findVal2, string &path, string &direction1, string &direction2){
        if(!root)
            return ;
        if(direction1.size() && direction2.size())
            return ;
        if(root->val == findVal1)
            direction1 = path;
        if(root->val == findVal2)
            direction2 = path;

        path+= "L";
        findDirections(root->left, findVal1, findVal2, path, direction1, direction2);
        
        path.back() = 'R';
        findDirections(root->right, findVal1, findVal2, path, direction1, direction2);
        
        path.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // temp = x for optimization
        string startDirection ="", destDirection = "", temp = "x";
        findDirections(root, startValue, destValue, temp, startDirection, destDirection);
        
        reverse(startDirection.begin(), startDirection.end());
        reverse(destDirection.begin(), destDirection.end());

        while(startDirection.size() && destDirection.size() && startDirection.back()==destDirection.back())
            startDirection.pop_back(),
            destDirection.pop_back();

        reverse(destDirection.begin(), destDirection.end());
        return string(startDirection.size(), 'U') + destDirection;
    }
};