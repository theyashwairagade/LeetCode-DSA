class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();

        // Spliting by / is done here
        vector<string> operations;
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/' && temp=="")    continue;
            if(path[i]=='/')
            {
                operations.push_back(temp);
                temp="";
            }else   temp+=path[i];
        }
        if(temp!="")    operations.push_back(temp); //edge case

        // Ordering them
        stack <string> stk;
        for(auto str:operations)
        {
            if(str==".." && !stk.empty())   stk.pop();
            else if(str!=".." && str!=".")  stk.push(str);
        }

        if(stk.empty()) return "/"; // To reduce time and simpler problem

        // Started creating answer
        path="";
        while(!stk.empty())
        {
            path="/"+stk.top()+path;
            stk.pop();
        }
        return path;
    }
};