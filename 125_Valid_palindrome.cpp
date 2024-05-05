class Solution {
public:
    bool isalphabet(char A)
    {
        if((int(A)>=int('a') && int(A)<=int('z'))||(int(A)>=int('0') && int(A)<=int('9')))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(isupper(s[left]))   s[left]=tolower(s[left]);
            if(isupper(s[right]))   s[right]=tolower(s[right]);
            if(isalphabet(s[left]) && isalphabet(s[right]))
            {
                if(s[left]!=s[right])   return false;
                left++;
                right--;
            }
            else
            {
                if(!isalphabet(s[left]))   left++;
                if(!isalphabet(s[right]))  right--;
            }
        }
        return true;
    }
};