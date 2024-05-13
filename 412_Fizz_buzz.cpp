class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        ans.push_back(to_string(1));
        for(int i=2;i<=n;i++)
        {
            if(i%15==0) ans.push_back("FizzBuzz");
            else if(i%5==0) ans.push_back("Buzz");
            else if(i%3==0) ans.push_back("Fizz");
            else    ans.push_back(to_string(i));;
        }
        return ans;
    }
};