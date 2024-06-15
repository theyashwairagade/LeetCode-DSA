class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> array(n, 1);
        while(k--)
            for(int i=1; i< n; i++)
                array[i] = (static_cast<long long>(array[i]) + array[i - 1]) % 1000000007;
        return array[n-1];
    }
};