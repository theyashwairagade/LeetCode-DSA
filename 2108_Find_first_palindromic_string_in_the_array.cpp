class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string str:words)
        {   int length=str.size();
            int half=length/2;
            bool palimdrome=true;
            for(int i=0;i<half;i++)   
                if(str[i]!=str[length-i-1])
                {   palimdrome=false;
                    break;
                }
            if(palimdrome)  return str;
        }
        return "";
    }
};