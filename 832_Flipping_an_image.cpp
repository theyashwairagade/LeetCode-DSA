class Solution {
public:
    int reverse(int num)
    {
        if(num==0)  return 1;
        return 0;
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(vector<int> &a:image)
        {
            int begin=0,end=a.size()-1,temp;
            while(end>=begin)
            {
                temp=reverse(a[begin]);
                a[begin]=reverse(a[end]);
                a[end]=temp;
                end--;
                begin++;
            }
        }
        return image;
    }
};