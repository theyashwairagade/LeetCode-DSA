// Time complexity of O(n (logn)square ) and space complexity of O(n) using binary search
// class segmentTree{
//     private:
//         vector<int> tree;
//         int n;
//         int findMid(int a, int b)
//             {return a+(b-a)/2;}
//         void build(vector<int> &vec, int index, int left, int right)
//         {
//             if(left==right)
//             {    
//                 tree[index]= vec[left];
//                 return;
//             }
//             int mid=findMid(left, right);
//             build(vec, 2*index+1, left, mid);
//             build(vec, 2*index+2, mid+1, right);

//             // Need to change below accourding to question
//             tree[index]=tree[2*index+1] | tree[2*index+2];
//         }
//         int query(int index, int currentLeft, int currentRight, int findLeft, int findRight)
//         {
//             bool noOverlap= (findRight<currentLeft || currentRight<findLeft);
//             // Need to change below accourding to question
//             if(noOverlap)
//                 return 0;
//             bool completeOverlap= (findLeft <= currentLeft && currentRight <= findRight);
//             if(completeOverlap)
//                 return tree[index];
//             // If partial overlap
//             int mid=findMid(currentLeft,currentRight);
//             int left= query(2*index+1, currentLeft, mid, findLeft, findRight);
//             int right= query(2*index+2, mid+1, currentRight, findLeft, findRight);
//             // Need to change below accourding to question
//             return left | right;
//         }
//     public:
//         segmentTree(vector<int> vec)
//         {
//             n=vec.size();
//             tree.resize(4*n+1);
//             build(vec,0,0,n-1);
//         }
//         int query(int left, int right)
//             {return query(0, 0, n-1, left, right);}
// };
// class Solution {
//     int findMid(int a, int b)
//         {return a+(b-a)/2;}
// public:
//     int minimumDifference(vector<int>& nums, int k) {
//         int n=nums.size();
//         int ans=INT_MAX;
//         segmentTree seg(nums);

//         for(int i=0; i<n; i++)
//         {
//             if(nums[i]>=k)
//             {
//                 ans=min(ans, nums[i]-k );
//                 continue;
//             }
//             int left=i, right=n-1;
//             while(left<=right)
//             {
//                 int mid=findMid(left, right);
//                 int rangeOR= seg.query(i,mid);
//                 ans=min(ans, abs(rangeOR-k));
//                 if(rangeOR>k)
//                     right=mid-1;
//                 else
//                     left=mid+1;
//             }
//         }
//         return ans;
//     }
// };





// optimizing further using sliding window concept with timeComplexity of O(n logn) and space complexity of O(n)
// class segmentTree{
//     private:
//         vector<int> tree;
//         int n;
//         int findMid(int a, int b)
//             {return a+(b-a)/2;}
//         void build(vector<int> &vec, int index, int left, int right)
//         {
//             if(left==right)
//             {    
//                 tree[index]= vec[left];
//                 return;
//             }
//             int mid=findMid(left, right);
//             build(vec, 2*index+1, left, mid);
//             build(vec, 2*index+2, mid+1, right);

//             // Need to change below accourding to question
//             tree[index]=tree[2*index+1] | tree[2*index+2];
//         }
//         int query(int index, int currentLeft, int currentRight, int findLeft, int findRight)
//         {
//             bool noOverlap= (findRight<currentLeft || currentRight<findLeft);
//             // Need to change below accourding to question
//             if(noOverlap)
//                 return 0;
//             bool completeOverlap= (findLeft <= currentLeft && currentRight <= findRight);
//             if(completeOverlap)
//                 return tree[index];
//             // If partial overlap
//             int mid=findMid(currentLeft,currentRight);
//             int left= query(2*index+1, currentLeft, mid, findLeft, findRight);
//             int right= query(2*index+2, mid+1, currentRight, findLeft, findRight);
//             // Need to change below accourding to question
//             return left | right;
//         }
//     public:
//         segmentTree(vector<int> vec)
//         {
//             n=vec.size();
//             tree.resize(4*n+1);
//             build(vec,0,0,n-1);
//         }
//         int query(int left, int right)
//             {return query(0, 0, n-1, left, right);}
// };
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums, int k) {
//         int n=nums.size();
//         int ans=INT_MAX;
//         segmentTree seg(nums);

//         int left=0, right=0;
//         while(left<=right && right<n)
//         {
//             int rangeOr=seg.query(left,right);
//             ans=min(ans, abs(rangeOr-k));
//             if(rangeOr==k)
//                 return 0;
//             if(rangeOr<k)
//                 right++;
//             else
//                 left++;
//             if(left>right)
//                 right++;
//         }
//         return ans;
//     }
// };





// Optimizing with concept of prefix sum in time complexity of O(n) and space complexity of O(1)
class bitOR{
    vector<int> bit;
public:
    void add(int num)
    {
        for(int i=0; i<32; i++)
            if(num & (1 << i))
                bit[i]++;
    }
    void subtract(int num)
    {
        for(int i=0; i<32; i++)
            if(num & (1 << i))
                bit[i]--;
    }
    int calculate()
    {
        int ans=0;
        for(int i=0; i<32; i++)
            if(bit[i])
                ans+=1<<i;
        return ans;
    }
    bitOR(int num)
    {
        bit.resize(32);
        add(num);
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;

        int left=0, right=0;
        bitOR prefixSum(nums[left]);
        while(left<=right && right<n)
        {
            int rangeOr=prefixSum.calculate();
            ans=min(ans, abs(rangeOr-k));
            if(rangeOr==k)
                return 0;
            if(rangeOr<k)
            {
                right++;
                if(right<n)
                    prefixSum.add(nums[right]);
            }
            else
            {
                prefixSum.subtract(nums[left]);
                left++;
            }
            if(left>right)
            {
                right++;
                if(right<n)
                    prefixSum.add(nums[right]);
            }
        }
        return ans;
    }
};