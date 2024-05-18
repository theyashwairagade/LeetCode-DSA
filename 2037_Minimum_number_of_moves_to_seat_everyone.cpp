class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans=0;
        int length=seats.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i=0;i<length;i++)   ans+=abs(seats[i]-students[i]);
        return ans;
    }
};