class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();

        int ans=0;
        ans+=min(n,8);

        n-=8;
        if(n>0)
            ans+=min(2*n,16);
        
        n-=8;
        if(n>0)
            ans+=min(3*n,24);

        n-=8;
        if(n>0)
            ans+=4*n;
        
        return ans;
    }
};





// making code looks smaller
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();

        int ans=0;
        for(int i=1; n>0; i++)
        {
            ans+=min(i*n,i*8);
            n-=8;
        }        
        return ans;
    }
};