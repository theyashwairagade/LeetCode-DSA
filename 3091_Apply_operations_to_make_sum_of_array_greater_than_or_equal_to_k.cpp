// Brutte force in O(k) time complexity and space complexity is O(1)
class Solution {
public:
    int minOperations(int k) {
        if(k==1)    return 0;
        int ans=k;
        // Here a is for increasing and (k-1)/(a+1) is for duplication
        // we used k-1 as for 12/4 is 3 but in case of 12 we want to duplicate 4 only 2 times
        // we used a+1 because by default we have 1
        for(int a=0;a<k;a++)
            ans=min(ans,a+(k-1)/(a+1));
        return ans;
    }
};


// math method in time complexity of O(1) and space complexity of O(1)
class Solution {
public:
    int minOperations(int k) {
        if(k==1)    return 0;
        int a=ceil(sqrt(k));
        return a+ceil(float(k)/(a))-2;
    }
};

// More optimized math approach
class Solution {
public:
    int minOperations(int k) {
        return ceil(2*(sqrt(k)-1));
    }
};