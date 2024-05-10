class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int index=num.size()-1;
        while(k && index>=0)
        {
            num[index]+=k;
            k=num[index]/10;
            num[index]%=10;
            index--;
        }
        if(!k)  return num;
        reverse(num.begin(),num.end());
        while(k)
        {
            num.push_back(k%10);
            k/=10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};