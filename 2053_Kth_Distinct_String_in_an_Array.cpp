class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinct, duplicate;

        for(auto &str: arr)
            if(duplicate.find(str)==duplicate.end())
                if(distinct.find(str)==distinct.end())
                    distinct.insert(str);
                else
                    distinct.erase(str),
                    duplicate.insert(str);
        int count = 1;
        for(auto &str: arr)
            if(distinct.find(str)!=distinct.end())
                if(count == k)
                    return str;
                else
                    count++;
        return "";
    }
};