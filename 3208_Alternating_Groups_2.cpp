class Solution {
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();

        for(int i=1; i+1<n; i++)
            if(colors[i-1]!=colors[i] && colors[i]!=colors[i+1])
                ans++;
        
        if(colors[n-1]!=colors[0] && colors[0]!= colors[1])
            ans++;
        if(colors[n-2]!=colors[n-1] && colors[n-1]!=colors[0])
            ans++;
        return ans;
    }
    bool differentFromPrev(int index, vector<int> &colors, int &n){
        if(index == 0)
            return colors[n-1] != colors[index]; // Compare with the last element if index is 0
        return colors[index-1] != colors[index]; // Compare with the previous element otherwise
    }

    bool differentFromNext(int index, vector<int> &colors, int &n){
        if(index+1 < n)
            return colors[index] != colors[index+1]; // Compare with the next element if within bounds
        return colors[index] != colors[0]; // Compare with the first element if index is the last element
    }

public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        cout<<"Check 1"<<endl;
        if(k==3)
            return numberOfAlternatingGroups(colors);
        int n = colors.size();
        int ans = 0;
        int left = 0;

        cout<<"Check 2"<<endl;
        // Finding inital
        while(left<n){
            cout<<"left= "<<left<<endl;
            if(differentFromPrev(left, colors, n) && differentFromNext(left, colors, n))
                break;
            left++;
        }
        cout<<"Check 3"<<endl;

        int right = left;
        cout<<"while started from left= "<<left<<" right= "<<right<<endl;
        while(right < n){
            if(right-left == k-3){
                ans ++,
                left++;
                cout<<"Case 1 "<<" left= "<<left<<" right= "<<right<<" ans= "<<ans<<endl;
                continue;
            }
            if(right+1 < n && differentFromPrev(right+1, colors, n) && differentFromNext(right+1, colors, n)){
                right++;
                cout<<"Case 2 "<<" left= "<<left<<" right= "<<right<<endl;
                continue;
            }
            left = right +1;
            while(left<n){
                if(differentFromPrev(left, colors, n) && differentFromNext(left, colors, n))
                    break;
                left++;
            }
            right = left;
            cout<<"Case 3 "<<" left= "<<left<<" right= "<<right<<endl;
        }
        return ans;
    }
};





// Checking 
class Solution {
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();

        for(int i=1; i+1<n; i++)
            if(colors[i-1]!=colors[i] && colors[i]!=colors[i+1])
                ans++;
        
        if(colors[n-1]!=colors[0] && colors[0]!= colors[1])
            ans++;
        if(colors[n-2]!=colors[n-1] && colors[n-1]!=colors[0])
            ans++;
        return ans;
    }
    void insertLast(int k, vector<int> &colors){
        for(int i=0; i<k; i++)
            colors.push_back(colors[i]);
    }
    bool isValid(int index, vector<int> &colors){
        return ((colors[index-1]!=colors[index]) && (colors[index]!=colors[index+1]));
    }
    // void print(vector<int> &vec){
    //     for(auto &i: vec)
    //         cout<<i<<" ";
    //     cout<<endl;
    // }
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        if(k==3)
            return numberOfAlternatingGroups(colors);
        int n = colors.size(),
            ans = 0;

        insertLast(k, colors);
        // cout<<"For vector ";
        // print(colors);
        int newN = colors.size();

        int left = 1;
        while(left+1<newN){
            if(isValid(left, colors))
                break;
            left++;
        }

        int right = left;
        // cout<<"While started from left= "<<left<<" right= "<<right<<endl;
        while(right+2 < newN){
            if(right-left == k-3){
                ans ++,
                left++;
                // cout<<"Case 1 "<<" left= "<<left<<" right= "<<right<<" ans= "<<ans<<endl;
                continue;
            }
            if(right + 3 < newN && isValid(right+1, colors)){
                right++;
                // cout<<"Case 2 "<<" left= "<<left<<" right= "<<right<<endl;
                continue;
            }
            left = right +1;
            while(left+1<newN){
                if(isValid(left, colors))
                    break;
                left++;
            }
            right = left;
            // cout<<"Case 3 "<<" left= "<<left<<" right= "<<right<<endl;
        }
        return ans;
    }
};