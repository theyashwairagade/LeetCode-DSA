class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        bool working=false;
        do
        {
            for(;i<haystack.size();i++)
            {
                if(haystack[i]==needle[0])  
                {
                    working=true;
                    break;
                }
                
            }
            if(!working)    return -1;
            for(int j=0;j<needle.size();j++)
                if(haystack[i+j]!=needle[j])
                {
                    working=false;
                    break;
                }
            if(working) return i;
        }
        while((i++)<haystack.size());
        return -1;
    }
};