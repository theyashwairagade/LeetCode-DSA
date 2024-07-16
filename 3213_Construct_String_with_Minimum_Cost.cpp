// Inspired by Word Break II of leetcode but give MLE
class Solution {
    void solve(string s, int &n, vector<string> &words, vector<int> &costs, unordered_map<string, int> &dp){
        if(dp.find(s)!=dp.end())
            return;

        // vector<string> ans; 
        int ans = 1e6;
        for(int i=0; i<n; i++){
            string word = words[i];
            int cost = costs[i],
                len = word.size();

            string iGot = s.substr(0,len);

            if(iGot != word)
                continue;
            
            string remaining = s.substr(len);
            solve(remaining, n, words, costs, dp);
            ans = min(ans, cost + dp[remaining]);
        }
        dp[s]=ans;
    }
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        unordered_map<string, int> dp;
        dp[""]=0;
        int n = words.size();
        solve(target, n, words, costs, dp);
        return dp[target]>=1e6 ? -1 : dp[target];
    }
};





// Optimization but still gives TLE but sufficient for interview
class TrieNode{
public:
    char c;
    int cost;
    TrieNode* children[26];
    TrieNode(char c){
        this->c = c;
        cost = 1e7;
        for(int i=0; i<26; i++)
            children[i]=NULL;
    }
};
class Solution {
public:
    TrieNode *root;
    void addString(string &s, int inputCost){
        TrieNode *current = root;
        for(auto &c: s){
            if(!current->children[c-'a'])
                current->children[c-'a']= new TrieNode(c);
            current = current ->children[c-'a'];
        }
        current->cost = min(current->cost, inputCost);
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        root = new TrieNode('/');
        int n = target.size();
        vector<long long> dp = vector<long long> (n+1, INT_MAX);
        
        for(int i=0; i<words.size(); i++)
            addString(words[i], costs[i]);

        dp[0]=0;
        for(int i=0; i<n; i++){
            if(dp[i]==INT_MAX)
                continue;
            TrieNode* current = root;
            for(int j=i; j<n; j++){
                char c = target[j];
                if(!current->children[c-'a'])
                    break;
                current = current->children[c-'a'];
                if(current->cost!=1e7)
                    dp[j+1]= min(dp[j+1], current->cost + dp[i]);
            }
        }
        return (dp[n]== INT_MAX) ? -1 : dp[n];
    }
};





// Optimized using Aho-Corasick
const int mxN = 1e6 + 5;
int to[mxN][26], sl[mxN], term[mxN], d[mxN][26], de[mxN], id[mxN];
int cur = 0;
 
void add_string(const string &s, int i){
	int u = 0;
	for(char c: s){
		if(!to[u][c - 'a'])
			to[u][c - 'a'] = ++cur;
		u = to[u][c - 'a'];
	}	
	term[u] = u;
    id[u] = i;
}
 
void push_sl(){
	queue<int> q;
	q.push(0);
	while(q.size()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 26; ++i){
			int v = to[u][i];
			if(v){
				sl[v] = d[sl[u]][i];
				if(!term[v])
					term[v] = term[sl[v]];
				de[v] = de[u] + 1;	
				d[u][i] = v;
				q.push(v);
			}else
				d[u][i] = d[sl[u]][i];	
 
		}
	}	
}

const int inf = 1e9;

class Solution {
public:
    int minimumCost(string t, vector<string>& w, vector<int>& c) {
        int n = w.size();
        map<string, int> mp;
        for(int i = 0; i < n; ++i){
            if(mp.find(w[i]) != mp.end())
                mp[w[i]] = min(mp[w[i]], c[i]);
            else
                mp[w[i]] = c[i];
        }
        int total = 0;
        for(const string& s: w){
            total += s.size();
        }

        cur = 0;
        for(int i = 0; i <= total + 5; ++i){
            sl[i] = term[i] = de[i] = 0; 
            for(int j = 0; j < 26; ++j){
                to[i][j] = d[i][j] = 0;
            }
        }

        for(int i = 0; i < n; ++i){
            if(mp[w[i]] == c[i])
                add_string(w[i], i);
        }
        push_sl();
        vector<int> dp(t.size() + 1, inf);
        dp[0] = 0;
        int u = 0;
        for(int i = 1; i <= t.size(); ++i){
            u = d[u][t[i - 1] - 'a'];
            int v = term[u];
            while(v){
                dp[i] = min(dp[i], c[id[v]] + dp[i - de[v]]);
                v = term[sl[v]];
            }
        }
        return dp.back() == inf ? -1 : dp.back();
    }
};