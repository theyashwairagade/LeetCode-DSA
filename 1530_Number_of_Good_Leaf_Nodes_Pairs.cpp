class Solution {
    vector<int> solve(TreeNode* root, int &distance, int &ans){
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {1};
        
        auto fromLeft = solve(root->left, distance, ans),
             fromRight = solve(root->right, distance, ans);
        
        for(auto &i: fromLeft)
            for(auto &j: fromRight)
                if(i+j<=distance)
                    ans++;
        
        vector<int> returnAns;
        for(auto &i: fromLeft)
            if(i+1<distance)
                returnAns.push_back(i+1);
        for(auto &i: fromRight)
            if(i+1<distance)
                returnAns.push_back(i+1);
        
        return returnAns;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};





// Can be optimized slightly by using unordered map of int, int to store frequency rather than actual values