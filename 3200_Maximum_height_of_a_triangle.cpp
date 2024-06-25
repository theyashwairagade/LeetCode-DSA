class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int currentBlue = blue, currentRed = red;
        int ans;
        for(int i=1; ; i++)
            if(i%2)
                if(red<i)
                {
                    ans = i-1;
                    break;
                }
                else
                    red-=i;
            else
                if(blue<i)
                {
                    ans = i-1;
                    break;
                }
                else
                    blue-=i;

        for(int i=1; ; i++)
            if(i%2)
                if(currentBlue<i)
                {
                    ans = max(ans, i-1);
                    break;
                }
                else
                    currentBlue-=i;
            else
                if(currentRed<i)
                {
                    ans = max(ans, i-1);
                    break;
                }
                else
                    currentRed-=i;
        return ans;
    }
};