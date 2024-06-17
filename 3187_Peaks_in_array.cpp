class SegmentTree{
    private:
        vector<int> tree;
        int n;
        int findMid(int a, int b)
            {return a+(b-a)/2;}
        void build(vector<int> &vec, int index, int left, int right)
        {
            if(left==right)
            {   
                if(left && left+1 < vec.size() && vec[left-1]<vec[left] && vec[left]> vec[left+1])
                    tree[index]=1;
                else
                    tree[index]=0;
                return;
            }
            int mid=findMid(left, right);
            build(vec, 2*index+1, left, mid);
            build(vec, 2*index+2, mid+1, right);

            // Need to change below accourding to question
            tree[index]=tree[2*index+1] + tree[2*index+2];
        }
        int query(int index, int currentLeft, int currentRight, int findLeft, int findRight)
        {
            bool noOverlap= (findRight<currentLeft || currentRight<findLeft);
            // Need to change below accourding to question
            if(noOverlap)
                return 0;
            bool completeOverlap= (findLeft <= currentLeft && currentRight <= findRight);
            if(completeOverlap)
                return tree[index];
            // If partial overlap
            int mid=findMid(currentLeft,currentRight);
            int left= query(2*index+1, currentLeft, mid, findLeft, findRight);
            int right= query(2*index+2, mid+1, currentRight, findLeft, findRight);
            // Need to change below accourding to question
            return left + right;
        }
        void update(int index, int left, int right, int findIndex, int val)
        {
            if(left==right)
            {
                // Need to change below accourding to question
                tree[index]=val;
                return;
            }
            // If partial overlap
            int mid=findMid(left, right);
            if(left<=findIndex && findIndex<=mid)
                update(2*index+1, left, mid, findIndex, val);
            else
                update(2*index+2, mid+1, right, findIndex, val);
            int leftTree=tree[2*index+1];
            int rightTree= tree[2*index+2];
            // Need to change below accourding to question
            tree[index]=leftTree + rightTree;
        }
    public:
        SegmentTree(vector<int> vec)
        {
            n=vec.size();
            tree.resize(4*n+1);
            build(vec,0,0,n-1);
        }
        void update(int index, int val)
            {update(0, 0, n-1, index, val);}
        int query(int left, int right)
            {return query(0, 0, n-1, left+1, right-1);}
};

class Solution {
    bool corner(vector<int>& nums, int index)
        {return !(0<index && index+1<nums.size());}
    int valOfIndex(vector<int> &nums, int index)
    {
        // cout<<"Val of index= "<<index;
        if(!corner(nums, index) && nums[index-1]<nums[index] && nums[index]>nums[index+1])
        {
            // cout<<"is one"<<endl;
            return 1;
        }
        // cout<<"is zero"<<endl;
        return 0;
    }
    void print(vector<int> &arr)
    {
        for(int &i: arr)
            cout<<i<<" ";
        cout<<endl;
    }
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        SegmentTree seg(nums);
        for(auto &query: queries)
        {
            if(query[0] == 1)
            {
                ans.push_back(seg.query(query[1], query[2]));
                continue;
            }
            int index = query[1];
            int newVal = nums[index] = query[2];
            seg.update(index, valOfIndex(nums, index));
            if(index)
                seg.update(index-1, valOfIndex(nums, index-1));
            if(index+1 < nums.size())
                seg.update(index+1, valOfIndex(nums, index+1));
            // print(nums);
        }
        return ans;
    }
};