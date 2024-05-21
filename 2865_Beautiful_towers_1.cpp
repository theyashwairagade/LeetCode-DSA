class Solution {
public:
    long long maximumSumOfHeights(vector<int>& v) {
        int n= v.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            int prev= v[i];
            long long sum=v[i];
            for(int j=i-1; j>=0; j--){
                prev= min(v[j],prev);
                sum+= prev;  

            }
            prev=v[i];
            for(int j= i+1; j<n; j++){
                prev= min(prev,v[j]);
                sum+= prev;
            }
            if(sum>ans) ans=sum;
        }
        return ans;
        
    }
};