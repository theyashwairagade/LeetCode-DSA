class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size()/2;
        if(!n)    return "";
        for(int i=0;i<n;i++)
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
            }
        palindrome[palindrome.size()-1]='b';
        return palindrome;
    }
};