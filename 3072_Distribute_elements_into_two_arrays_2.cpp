// // Solution using policy based data structure
// #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/detail/standard_policies.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<
//     int,                        // Key type: type of elements in the set is int
//     null_type,                  // Mapped policy: since it's a set and not a map, we use `null_type`.
//     greater_equal<int>,         // Key comparison function: elements are stored in descending order, allowing duplicates.
//     rb_tree_tag,                // Tree type: specifies that the underlying data structure is a red-black tree.
//     tree_order_statistics_node_insert // Node insert policy: provides ability to get the k-th largest/smallest element.
// > orderedSet;


// do research on find_by_order too
// order_of_key gives lower bound behavior 
// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums) {
//         int n=nums.size();
//         orderedSet o1, o2;
//         vector<int> arr1, arr2;

//         o1.insert(nums[0]);
//         o2.insert(nums[1]);
//         arr1.push_back(nums[0]);
//         arr2.push_back(nums[1]);

//         for(int i=2; i<n; i++)
//         {
//             int val=nums[i];
//             int greaterCountArr1=o1.order_of_key(val);
//             int greaterCountArr2=o2.order_of_key(val);
//             if(greaterCountArr1>greaterCountArr2)
//             {
//                 o1.insert(val);
//                 arr1.push_back(val);
//             }else if(greaterCountArr2>greaterCountArr1 || o2.size()<o1.size())
//             {
//                 o2.insert(val);
//                 arr2.push_back(val);
//             }else{
//                 o1.insert(val);
//                 arr1.push_back(val);
//             }
//         }
//         for(auto &i: arr2)
//             arr1.push_back(i);
//         return arr1;
//     }
// };





// Solution using segment tree
// class segmentTree{
//     private:
//         vector<int> tree;
//         int n;
//         int findMid(int a, int b)
//             {return a+(b-a)/2;}
//         int greaterCount(int index, int currentLeft, int currentRight, int findLeft, int findRight)
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
//             int left= greaterCount(2*index+1, currentLeft, mid, findLeft, findRight);
//             int right= greaterCount(2*index+2, mid+1, currentRight, findLeft, findRight);
//             // Need to change below accourding to question
//             return left+right;
//         }
//         void insert(int index, int left, int right, int findIndex)
//         {
//             if(left==right)
//             {
//                 // Need to change below accourding to question
//                 tree[index]++;
//                 return;
//             }
//             // If partial overlap
//             int mid=findMid(left, right);
//             if(left<=findIndex && findIndex<=mid)
//                 insert(2*index+1, left, mid, findIndex);
//             else
//                 insert(2*index+2, mid+1, right, findIndex);
//             int leftTree=tree[2*index+1];
//             int rightTree= tree[2*index+2];
//             // Need to change below accourding to question
//             tree[index]=leftTree+rightTree;
//         }
//     public:
//         vector<int> array;
//         segmentTree(int size)
//         {
//             n=size;
//             tree.resize(4*n+1);
//         }
//         void insert(int index, int val)
//         {
//             array.push_back(val);
//             insert(0, 0, n-1, index);
//         }
//         int greaterCount(int right)
//             {return greaterCount(0, 0, n-1, 0, right-1);}
//         int numberOfElements()
//             {return array.size();}
// };
// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums) {
//         int n=nums.size();
//         // Compressing segment tree i.e. Coordinate compression starts
//         set<int, greater<int>> st;
//         for(auto &i: nums)
//             st.insert(i);
        
//         unordered_map<int,int> index;
//         int temp=0;
//         for(auto &i: st)
//             index[i]=temp++;
//         // Compressing segment tree i.e. Coordinate compression ends
        
//         segmentTree arr1(st.size()), arr2(st.size());
//         arr1.insert(index[nums[0]],nums[0]);
//         arr2.insert(index[nums[1]],nums[1]);

//         for(int i=2; i<nums.size(); i++)
//         {
//             int arr1GreaterCount=arr1.greaterCount(index[nums[i]]);
//             int arr2GreaterCount=arr2.greaterCount(index[nums[i]]);
//             if(arr1GreaterCount>arr2GreaterCount)
//                 arr1.insert(index[nums[i]], nums[i]);
//             else if(arr1GreaterCount<arr2GreaterCount)
//                 arr2.insert(index[nums[i]], nums[i]);
//             else if(arr1.numberOfElements()>arr2.numberOfElements())
//                 arr2.insert(index[nums[i]], nums[i]);
//             else
//                 arr1.insert(index[nums[i]], nums[i]);
//         }
//         for(auto &i: arr2.array)
//             arr1.array.push_back(i);
//         return arr1.array;
//     }
// };




// Solution using frenwick tree
class fenwickTree{
    private:
        int n;
        vector<int> tree;
    public:
        vector<int> array;
        void insert(int index, int val)
        {
            index++;
            array.push_back(val);
            while(index<=n)
            {
                tree[index]++;
                index+= (index & -index);
            }
        }
        int greaterCount(int index)
        {
            int ans=0;
            while(index>0)
            {
                ans+=tree[index];
                index-= (index & -index);
            }
            return ans;
        }
        int numberOfElements()
            {return array.size();}
        fenwickTree(int size)
        {
            n=size;
            tree.resize(n+1, 0);
        }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        // Compressing segment tree i.e. Coordinate compression starts
        set<int, greater<int>> st;
        for(auto &i: nums)
            st.insert(i);
        
        unordered_map<int,int> index;
        int temp=0;
        for(auto &i: st)
            index[i]=temp++;
        // Compressing segment tree i.e. Coordinate compression ends
        
        fenwickTree arr1(st.size()), arr2(st.size());
        arr1.insert(index[nums[0]],nums[0]);
        arr2.insert(index[nums[1]],nums[1]);

        for(int i=2; i<nums.size(); i++)
        {
            int arr1GreaterCount=arr1.greaterCount(index[nums[i]]);
            int arr2GreaterCount=arr2.greaterCount(index[nums[i]]);
            if(arr1GreaterCount>arr2GreaterCount)
                arr1.insert(index[nums[i]], nums[i]);
            else if(arr1GreaterCount<arr2GreaterCount)
                arr2.insert(index[nums[i]], nums[i]);
            else if(arr1.numberOfElements()>arr2.numberOfElements())
                arr2.insert(index[nums[i]], nums[i]);
            else
                arr1.insert(index[nums[i]], nums[i]);
        }
        for(auto &i: arr2.array)
            arr1.array.push_back(i);
        return arr1.array;
    }
};