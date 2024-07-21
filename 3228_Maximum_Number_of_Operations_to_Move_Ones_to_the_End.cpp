class Solution {
public:
    int maxOperations(string s) {
        bool swapA = true;
        int ans = 0, countOnes = 0;
        for(auto &c: s)
            if(c=='0')
                swapA = true;
            else{
                if(swapA)
                    ans+= countOnes,
                    swapA = false;
                countOnes++;
            }
        if(swapA)
            ans+= countOnes,
            swapA = false;
        return ans;
    }
};