// Using vector as at that time i don't know hashmaps
class Solution {
private:
vector<int> v;
public:
    bool isPresent(int n)
    {
        for(int i=0;i<v.size();i++)
            if(v[i]==n) return true;
        v.push_back(n);
        return false;
    }
    bool isHappy(int n) {
        while(n!=1)
        {
            if(isPresent(n))    return false;
            int sq=0;
            while(n)
            {
                sq+=(n%10)*(n%10);
                n/=10;
            }
            n=sq;
        }
        return true;
    }
};



class Solution {
private:
public:
    bool isHappy(int n) {
        unordered_map<int,bool> mp;
        while(n!=1)
        {
            if(mp.count(n))    return false;
            mp[n]=true;
            int sq=0;
            while(n)
            {
                sq+=(n%10)*(n%10);
                n/=10;
            }
            n=sq;
        }
        return true;
    }
};