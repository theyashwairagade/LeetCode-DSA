// Brutte Force approach
class Solution {
public:
    bool divisor(int &a, int &num)
        {return !(num%a);}
    unordered_map<char,int> mapping(string &s, int start, int &len)
    {
        unordered_map<char,int> mp;
        for(int end=start+len;start<end;start++)
            mp[s[start]]++;
        return mp;
    }
    bool equal(const unordered_map<char,int> &mp1,const unordered_map<char,int> &mp2)
    {
        for(const auto &pr:mp1)
        {
            auto it = mp2.find(pr.first);
            if (it == mp2.end() || it->second != pr.second)
                return false;
        }
        return true;
    }
    bool validAnagramConcatenation(string &s, int &len)
    {
        int n=s.size();
        unordered_map<char,int> mp=mapping(s,0,len);
        for(int i=len;i<n;i+=len)
            if(!equal(mp,mapping(s,i,len)))
                return false;
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        int end=n/2; // as it reduces time from n to n/2
        for(int i=1;i<=end;i++)
            if(divisor(i,n) && validAnagramConcatenation(s,i))
                return i;
        return n;
    }
};





// GCD approach working due to missing test cases
class Solution {
public:
    int gcd(int &a, int b)
    {
        while(a && b)
            if(a>b) a%=b;
            else    b%=a;
        return a+b;
    }
    int minAnagramLength(string s) {
        unordered_map<char,int> mp;
        for(const char &c: s)
            mp[c]++;
        
        int ans=mp[s[0]];
        for(const auto &pr: mp)
            ans=gcd(ans,pr.second);
        return s.size()/ans;
    }
};