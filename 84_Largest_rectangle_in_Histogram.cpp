// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         int leftSmaller[n], rightSmaller[n];
//         stack<int>stk;

//         // Finding leftSmaller
//         for(int i=0;i<n;i++)
//         {
//             while(!stk.empty() and heights[stk.top()]>=heights[i])
//                 stk.pop();
//             if(stk.empty())
//                 leftSmaller[i]=0;
//             else
//                 leftSmaller[i]=stk.top()+1;
//             stk.push(i);
//         }

//         while (!stk.empty())
//         stk.pop();

//         // Finding rightSmaller
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!stk.empty() and heights[stk.top()]>=heights[i])
//                 stk.pop();
//             if(stk.empty())
//                 rightSmaller[i]=n-1;
//             else
//                 rightSmaller[i]=stk.top()-1;
//             stk.push(i);
//         }

//         int ans=0;
//         for(int i=0;i<n;i++)
//             ans=max(ans,heights[i]*(rightSmaller[i]-leftSmaller[i]+1));
//         return ans;
//     }
// };





// Instead of finding rightSmaller and leftSmaller and storing them individually do that same in a single pass using only stack i.e. save space and time
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size() ;
        stack<int>stk;

        int ans=0;
        for(int i=0;i<=n;i++)
        {
            while(!stk.empty() && (i==n || heights[stk.top()]>=heights[i]))
            {
                int height=heights[stk.top()] ;
                stk.pop() ;
                int width=i ;
                if(!stk.empty())
                    width=i-stk.top()-1 ;

                ans=max(ans,height*width) ;
            }
            stk.push(i) ;
        }
        return ans ;
    }
};