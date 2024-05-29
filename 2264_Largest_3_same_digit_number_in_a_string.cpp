class Solution {
public:
    bool isValid(string &num, int startingIndex)
    {
        if(num[startingIndex]== num[startingIndex+1] && num[startingIndex]==num[startingIndex+2])
            return true;
        return false;
    }
    string largestGoodInteger(string num) {
        string ans="   ";
        int n= num.size();
        for(int i=0; i<n-2; i++)
            if(isValid(num, i))
            {
                cout<<"Working for "<<num.substr(i,3)<<endl;
                ans=max(ans, num.substr(i, 3));
            }
        return (ans!="   ")?ans: "";
    }
};