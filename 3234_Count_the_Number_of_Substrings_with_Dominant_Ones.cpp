class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> prefixOne(n, 0);
        prefixOne[0] = s[0] - '0';

        for (int i = 1; i < n; ++i) 
            prefixOne[i] = prefixOne[i - 1] + s[i]-'0';

        // Calculate the number of substrings
        for (int i = 0; i < n; i++){
            cout<<endl<<endl<<"i="<<i<<endl;
            for (int j = i; j < n; j++) {
                cout<<"j="<<j<<endl;
                int countOne = prefixOne[j] - (i? prefixOne[i-1] : 0);
                int countZero = j - i + 1 - countOne;

                if (countZero * countZero > countOne) 
                    cout<<"not"<<endl,
                    j += ((countZero * countZero) - countOne - 1);  
                    // jump to the next possible solution

                else{
                    int sqrtOne = static_cast<int>(sqrt(countOne));
                    ans++;
                    cout<<"yes"<<endl;
                    // jump to where zero can be greater than countOne
                    if (sqrtOne > countZero) {  
                        // ensure not to exceed the n
                        ans += (j + sqrtOne - countZero) >= n ? (n - j - 1) : (sqrtOne - countZero); 
                        j += (sqrtOne - countZero);
                        cout<<"increment"<<endl;
                    }
                }
            }
        }
        return ans;
    }
};