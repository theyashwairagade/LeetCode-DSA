class Solution {
public:
    string originalDigits(string s) {
        string temp="egfihonsrutwvxz";
        map<char,int> mp;
        for(char character: temp)   mp[character]=0;
        
        for(char character: s)  mp[character]++;

        map<int,int> value;
        value[8]=mp['g'];
        value[4]=mp['u'];
        value[2]=mp['w'];
        value[6]=mp['x'];
        value[0]=mp['z'];
        value[3]=mp['h']-value[8];
        value[5]=mp['f']-value[4];
        value[7]=mp['s']-value[6];
        value[1]=mp['o']-value[0]-value[2]-value[4];
        value[9]=mp['i']-value[6]-value[8]-value[5];

        string strAns="";
        for(auto pair: value)
        {
            int times=pair.second;
            for(int i=0;i<times;i++)
                strAns+=to_string(pair.first);
        }
        return strAns;
    }
};