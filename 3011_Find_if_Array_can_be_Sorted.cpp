class Solution {
    // Log n
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    void bubbleSort(vector<int> &arr, unordered_map<int, int> &setBits){
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            bool flag = true;
            for (int j = 1; j <= n - i; j++)
                if (setBits[arr[j-1]]==setBits[arr[j]] && arr[j - 1] > arr[j])
                {
                    swap(arr[j - 1], arr[j]);
                    flag = false;
                }
            if (flag)  return;
        }
    }
public:
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> setBits;
        for(auto &i: nums)
            setBits[i]=countSetBits(i);
        
        bubbleSort(nums, setBits);
        int prev = 0;
        for(auto &i: nums)
            if(i<prev)
                return false;
            else
                prev = i;
        return true;
    }
};