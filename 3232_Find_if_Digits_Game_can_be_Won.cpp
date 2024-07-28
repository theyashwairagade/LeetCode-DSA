class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int countSingle = 0 ,countDouble = 0;
        for(auto &num: nums)
            if(num<10)
                countSingle+= num;
            else
                countDouble += num;
        return countSingle != countDouble;
    }
};