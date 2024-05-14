class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> memonize(k,0);
        for(int i=0;i<n;i++)
            memonize[i%k]+=energy[i];
        int ans=INT_MIN;
        for(auto &i: memonize)
            ans=max(ans,i);
        for(int i=0;i+k<n;i++)
            ans=max(ans,memonize[i%k]-=energy[i]);
        return ans;
    }
};