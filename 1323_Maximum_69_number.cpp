class Solution {
public:
    int maximum69Number (int num) {
        int index=0,temp=num;
        for(int i=1;temp;i++)
        {
            if(temp%10==6)  index=i;
            temp/=10;
        }
        if (!index) return num;
        temp=3;
        while(index>1)
        {
            temp*=10;
            index--;
        }
        return num+temp;
    }
};