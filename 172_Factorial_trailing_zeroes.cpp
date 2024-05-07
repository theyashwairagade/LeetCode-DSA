// Brutte Force approach time complexity is O(n*k) and space complexity of O(1)
class Solution {
public:
    int count5(int n)
    {
        int ans=0;
        while(n && n%5==0)
            ans++,n/=5;
        return ans;
    }
    int count2(int n)
    {
        int ans=0;
        while(n && n%2==0)
            ans++,n/=2;
        return ans;
    }
    int trailingZeroes(int n) {
        int two=0, five=0;
        n++;
        while(n--)
            two+=count2(n), five+=count5(n);

        return min(two, five);
    }
};

// Time complexity of O(logn) and space complexity of O(0)
// Reference Mohit Gupta youtube
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i*=5)
            ans+=n/i;
        
        return ans;
    }
};