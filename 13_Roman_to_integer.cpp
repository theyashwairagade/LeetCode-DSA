// Through array
class Solution {
public:
    int romanToInt(string str) 
    {
        int i=0,index=0,num=0;
        string symbols="MDCLXVI";
        int val[]={1000,500,100,50,10,5,1};
        while(str[i]!='\0')
            for(int j=0;j<7;j++)
                if(str[i]==symbols[j])
                {
                    if(index>j) num-=(2*val[index]);
                    num+=val[j];
                    index=j;
                    i++;
                    break;
                }
        return num;
    }
};

// Hash map 
class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> mp;
        int ans=0;
        mp['I']=1,mp['V']=5,mp['X']=10,mp['L']=50,mp['C']=100,mp['D']=500,mp['M']=1000;
        for(int i=0;i<s.size();i++)
            if(mp[s[i]]<mp[s[i+1]])
                ans-=mp[s[i]];
            else
                ans+=mp[s[i]];
        return ans;
    }
};