class Solution {
public:
    int decrypt(int number){
        int maxNum=0, n=number,ans=0;
        while (number){
            maxNum=max(maxNum,number%10);
            number/=10;
        }
        while(n){
            ans*=10;
            ans+=maxNum;
            n/=10;
        }
        return ans;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(int number:nums)    ans+=decrypt(number);
        return ans;
    }
};