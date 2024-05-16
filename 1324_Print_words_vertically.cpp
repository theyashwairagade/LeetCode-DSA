class Solution {
public:
    vector<string> printVertically(string s) 
    {
         int idx=0;
         int len=0;

         vector<string>words;

         while(idx<s.length())
         {
             if(idx<s.length() and s[idx]>='A' and s[idx]<='Z')
             {
                string word="";
                while(idx<s.length() and s[idx]>='A' and s[idx]<='Z')
                {
                    word.push_back(s[idx]);
                    idx++;
                }	
                if(word.length() > 0)
                {
                   words.push_back(word); 
                   if(word.length()>len)
                   {
                       len=word.length();
                   }
                }
             }	
         
             while(idx<s.length() and s[idx]==' ')
             {
                idx++;
             }

         }      
        
         vector<string>ans(len,"");
         
         for(int i=0;i<words.size();i++)
         {
              string currword=words[i];
              for(int j=0;j<len;j++)
              {
                  if(j<=currword.length()-1)
                  {
                     ans[j].push_back(currword[j]);             
                  }
                  else if(j>currword.length()-1)
                  {
                      ans[j].push_back(' ');
                  }
              }
         }
         vector<string>result;
         for(int i=0;i<ans.size();i++)
         {
             string currword = ans[i];
             int idx=-1;
             int j;
             for(j=0;j<currword.length();j++)
             {
                 if(currword[j]>='A' and currword[j]<='Z')
                 {
                     idx=j;
                 }
             }
             result.push_back(currword.substr(0,idx+1));
         }
         return result;
    }
};