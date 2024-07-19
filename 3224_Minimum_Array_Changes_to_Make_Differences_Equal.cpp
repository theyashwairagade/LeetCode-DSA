class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    void print(unordered_map<int,int> &mp){
        for(auto &pr: mp)
            cout<<pr.first<<"->"<<pr.second<<endl;
    }
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        int half = n/2;
        unordered_map<int, int> noChange, singleChange;
        for(int i=0; i<half; i++){
            int j = n-i-1;
            noChange[abs(nums[i]-nums[j])]++;
            int singleRange = max(max(nums[j], k- nums[j]), max(nums[i], k-nums[i]));
            singleChange[singleRange]++;
        }

        // cout<<"NoChange"<<endl;
        // print(noChange);
        // cout<<"singleChange"<<endl;
        // print(singleChange);

        vector<int> prefix(k+1);
        prefix[0]=half;

        for(int i=1; i<=k; i++)
            prefix[i]=prefix[i-1]-singleChange[i-1];

        print(prefix);
        int ans = n;
        for(int i=0; i<=k; i++)
            ans = min(ans, prefix[i]-noChange[i] + (half - prefix[i])*2);
        return ans;
    }
};