class Solution {
    bool present(string &current, vector<string> &bank){
        for(auto &str: bank)
            if(str == current)
                return true;
        return false;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string options = "ACGT";
        queue<string> q;
        unordered_set<string> alreadyAdded;

        q.push(startGene);
        alreadyAdded.insert(startGene);

        q.push("");
        int level = 0;

        while(q.size()>1){
            string current = q.front();
            q.pop();

            if(current == ""){
                level++,
                q.push("");
                continue;
            }

            if(current == endGene)
                return level;
            
            for(auto &c: current)
            {
                char original = c;
                for(auto &i: options)
                {
                    c=i;
                    
                    if(alreadyAdded.find(current)==alreadyAdded.end() && present(current, bank)){
                        if(current == endGene)
                            return level+1;
                        q.push(current),
                        alreadyAdded.insert(current);
                    }
                }
                c=original;
            }
        }
        return -1;
    }
};





// optimization
class Solution {
    bool oneDistance(string &a, string &b){
        int distance =0;
        for(int i=0; i<=8; i++)
            if(a[i]!=b[i])
                distance++;
        return distance == 1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string options = "ACGT";
        queue<string> q;
        unordered_set<string> alreadyAdded;

        q.push(startGene);
        alreadyAdded.insert(startGene);
        bank.push_back(startGene);

        q.push("");
        int level = 0;

        while(q.size()>1){
            string current = q.front();
            q.pop();

            if(current == ""){
                level++,
                q.push("");
                continue;
            }

            if(current == endGene)
                return level;
            
            for(auto &gene: bank){
                if(alreadyAdded.find(gene)==alreadyAdded.end() && oneDistance(current, gene)){
                    if(gene == endGene)
                        return level + 1;
                    q.push(gene),
                    alreadyAdded.insert(gene);
                }
            }
        }
        return -1;
    }
};