// optimized memonization of leftMax and rightMax in time complexity of O(n) and space complexity of O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int mx=height[0];
        vector<int> mem;

        // Storing max left
        for(int num:height)
        {
            mx=max(mx,num);
            mem.push_back(mx);
        }
        int ans=0;
        mx=INT_MIN;
        for(int i=height.size()-1;i>=0;i--)
        {
            mx=max(mx,height[i]);
            ans+=min(mx,mem[i])-height[i];
        }
        return ans;
    }
};


// Two pointer approach with time complexity as O(n) and space as O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }
        
        return ans;
    }
};

// Using stack with time complexity as O(n) and space complexity as O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            while(!stk.empty() && height[i]>=height[stk.top()])
            {
                int tp=stk.top();
                stk.pop();
                if(stk.empty()) break;// edge case
                int distance=i-stk.top()-1, ht=min(height[i],height[stk.top()])-height[tp];
                ans+=distance*ht;
            }
            stk.push(i);
        }
        return ans;
    }
};