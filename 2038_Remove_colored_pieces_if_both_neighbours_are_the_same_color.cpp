class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size()-1;
        int a=0,b=0;
        for(int i=1;i<n;i++)
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1])
                if(colors[i]=='A')  a++;
                else    b++;
        if(a>b) return true;
        return false;
    }
};