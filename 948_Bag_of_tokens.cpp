class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int length=tokens.size();
        if(!length) return 0;
        sort(tokens.begin(),tokens.end());
        int up=0;
        int down=length-1;
        int score=0;
        while(tokens[up]<tokens[down])
            if(power>=tokens[up])
            {
                score++;
                power-=tokens[up++];
            }    
            else if(score<=0)   break;
            else
            {
                score--;
                power+=tokens[down--];
            }
        if(power>=tokens[up])
        {
            score++;
            power-=tokens[up++];
        }
        return score;
    }
};