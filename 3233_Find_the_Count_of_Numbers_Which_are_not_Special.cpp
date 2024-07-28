class Solution {
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    // Function to find the next prime number
    int nextPrime(int n) {
        if (n <= 1)
            return 2;
        int prime = n;
        bool found = false;
        // Loop continuously until a prime number is found
        while (!found) {
            prime++;
            if (isPrime(prime))
                found = true;
        }
        return prime;
    }
public:
    int nonSpecialCount(int l, int r) {
        int prime = 2;
        int ans = r-l+1;
        while((long long)prime * prime <= r){
            if((long long)prime * prime >= l)
                ans--;
            prime= nextPrime(prime);
        }
        return ans;
    }
};