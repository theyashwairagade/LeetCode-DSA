class Solution {
    bool sameParity(char a, char b)
        {return a%2 == b%2;}
    void swap(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
    }
public:
    string getSmallestString(string s) {
        int n = s.size();
        for (int i = 0; i < n-1; i++) {
            if(sameParity(s[i], s[i+1]) && s[i]>s[i+1]){
                swap(s[i], s[i+1]);
                return s;
            }
        }
        return s;
    }
};