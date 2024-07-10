class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    void customSort(vector<int> &vec1, vector<int> &vec2, string &str){
        // Function used to sort vec2 accourding to vec1
        if(vec1.size()!=vec2.size()){
            cout<<"Both vectors have different size"<<endl;
            return;
        }
        
        int n = vec1.size();
        vector<size_t> index(n);
        
        for(size_t i=0; i<n; i++)
            index[i]=i;

        sort(index.begin(), index.end(), 
            [&](size_t i, size_t j) {return vec1[i]<vec1[j];});

        // If you want to do other vectors then can do here
        vector<int> dummyVec2(n);
        for(int i=0; i<n; i++)
            dummyVec2[i] = vec2[i];
        
        string dummyStr = str;

        for(size_t i=0; i<n; i++)
            vec2[i] = dummyVec2[index[i]],
            str[i] = dummyStr[index[i]];

        // If you want to sort vec1
        // sort(vec1.begin(), vec1.end());
        
        return;
    }
    long long findVal(int &health, char &direction){
        if(direction == 'R')
            return health;
        return (long long) health*(-1);
    }
    bool isEqual(long long a, long long b){
        return abs(a) == abs(b);
    }
    long long decremented(long long val){
        return (val<0) ? val+1 : val-1;
    }
    long long absMax(long long &a, long long &b){
        return (abs(a)>abs(b)) ? a : b;
    }
    bool sameDirection(long long a, long long b){
        return ((a<0 && b<0) || (a>0 && b>0));
    }
    bool zeroHealth(long long a){
        return a==0;
    }
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        customSort(positions, healths, directions);
        
        stack<long long> stk;
        for(int i=0; i<n; i++){
            long long current = findVal(healths[i], directions[i]);
            if(stk.empty()){
                stk.push(current);
                continue;
            }
            long long prev = stk.top();
            if(sameDirection(prev, current))
                stk.push(current);
            else if(isEqual(prev, current))
                stk.pop();
            else{
                stk.pop();
                stk.push(decremented(absMax(prev, current)));
                if(zeroHealth(stk.top()))
                    stk.pop();
            }
        }

        vector<int> ans;
        while(!stk.empty()){
            ans.push_back((int)abs(stk.top()));
            stk.pop();
        }

        // unordered_map<int, int> mp;
        // // used to store positon to the index
        // for(int i=0; i<n; i++)
        //     mp[positions[i]]=i;

        
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};





Solving problem to return in order of input
class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    vector<size_t> customSort(vector<int> &vec1, vector<int> &vec2, string &str){
        // Function used to sort vec2 accourding to vec1
        if(vec1.size()!=vec2.size()){
            cout<<"Both vectors have different size"<<endl;
            return {};
        }
        
        int n = vec1.size();
        vector<size_t> index(n);
        
        for(size_t i=0; i<n; i++)
            index[i]=i;

        sort(index.begin(), index.end(), 
            [&](size_t i, size_t j) {return vec1[i]<vec1[j];});

        // If you want to do other vectors then can do here
        vector<int> dummyVec2(n);
        for(int i=0; i<n; i++)
            dummyVec2[i] = vec2[i];
        
        string dummyStr = str;

        for(size_t i=0; i<n; i++)
            vec2[i] = dummyVec2[index[i]],
            str[i] = dummyStr[index[i]];

        // If you want to sort vec1
        // sort(vec1.begin(), vec1.end());
        
        return index;
    }
    long long findVal(int &health, char &direction){
        if(direction == 'R')
            return health;
        return (long long) health*(-1);
    }
    bool isEqual(pair<size_t, long long> a, pair<size_t, long long> b)
        {return abs(a.second) == abs(b.second);}
    pair<size_t, long long> decremented(pair<size_t, long long> pr)
        {return pr.second<0 ? make_pair(pr.first, pr.second+1) : make_pair(pr.first, pr.second-1);}
    pair<size_t, long long> absMax(pair<size_t, long long> a, pair<size_t, long long> b)
        {return (abs(a.second)>abs(b.second) ? a : b);}
    bool sameDirection(pair<size_t, long long> a, pair<size_t, long long> b)
        {return ((a.second<0 && b.second<0) || (a.second>0 && b.second>0));}
    bool zeroHealth(pair<size_t, long long> a)
        {return a.second==0;}
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        auto index = customSort(positions, healths, directions);
        
        stack<pair<size_t, long long>>stk;

        for(int i=0; i<n; i++){
            pair<size_t, long long> current = {index[i], findVal(healths[i], directions[i])};
            if(stk.empty()){
                stk.push(current);
                continue;
            }
            auto prev = stk.top();
            if(sameDirection(prev, current))
                stk.push(current);
            else if(isEqual(prev, current))
                stk.pop();
            else{
                stk.pop();
                stk.push(decremented(absMax(prev, current)));
                if(zeroHealth(stk.top()))
                    stk.pop();
            }
        }
        vector<pair<size_t, long long>> temp;

        while(!stk.empty()){
            temp.push_back(stk.top());
            stk.pop();
        }

        vector<int> ans;
        sort(temp.begin(), temp.end());
        for(auto &i: temp)
            ans.push_back((int)abs(i.second));
        return ans;
    }
};





// Solving problem of different direction but moving apart
class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    vector<size_t> customSort(vector<int> &vec1, vector<int> &vec2, string &str){
        // Function used to sort vec2 accourding to vec1
        if(vec1.size()!=vec2.size()){
            cout<<"Both vectors have different size"<<endl;
            return {};
        }
        
        int n = vec1.size();
        vector<size_t> index(n);
        
        for(size_t i=0; i<n; i++)
            index[i]=i;

        sort(index.begin(), index.end(), 
            [&](size_t i, size_t j) {return vec1[i]<vec1[j];});

        // If you want to do other vectors then can do here
        vector<int> dummyVec2(n);
        for(int i=0; i<n; i++)
            dummyVec2[i] = vec2[i];
        
        string dummyStr = str;

        for(size_t i=0; i<n; i++)
            vec2[i] = dummyVec2[index[i]],
            str[i] = dummyStr[index[i]];

        // If you want to sort vec1
        // sort(vec1.begin(), vec1.end());
        
        return index;
    }
    long long findVal(int &health, char &direction){
        if(direction == 'R')
            return health;
        return (long long) health*(-1);
    }
    bool isEqual(pair<size_t, long long> a, pair<size_t, long long> b)
        {return abs(a.second) == abs(b.second);}
    bool leftDirection(pair<size_t, long long> a)
        {return a.second<0;}
    bool rightDirection(pair<size_t, long long> a)
        {return a.second>0;}
    bool lowAbsVal(pair<size_t, long long> a, pair<size_t, long long> b)
        {return abs(a.second)<abs(b.second);}
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        auto index = customSort(positions, healths, directions);
        
        stack<pair<size_t, long long>>stk;

        for(int i=0; i<n; i++){
            pair<size_t, long long> current = {index[i], findVal(healths[i], directions[i])};

            if(stk.empty()){
                stk.push(current);
                continue;
            }
            auto prev = stk.top();

            // change some logic here
            if(leftDirection(current) && rightDirection(prev)){
                while(stk.size() && leftDirection(current) && rightDirection(stk.top())){
                    prev = stk.top();
                    if(isEqual(prev, current)){
                        stk.pop();
                        goto nextIteration;
                    }else if(lowAbsVal(prev, current))
                        stk.pop(),
                        current.second++;
                    else{
                        stk.pop();
                        prev.second--;
                        stk.push(prev);
                        goto nextIteration;
                    }
                }
                if(current.second)
                    stk.push(current);
            }
            else
                stk.push(current);
            nextIteration: ;
        }
        vector<pair<size_t, long long>> temp;

        while(!stk.empty()){
            temp.push_back(stk.top());
            stk.pop();
        }

        vector<int> ans;
        sort(temp.begin(), temp.end());
        for(auto &i: temp)
            ans.push_back((int)abs(i.second));
        return ans;
    }
};