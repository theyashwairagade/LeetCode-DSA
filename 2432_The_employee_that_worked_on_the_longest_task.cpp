class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int logsLen= logs.size();
        int maxTaskDuration=logs[0][1], ansId=logs[0][0];
        for(int i=1; i<logsLen; i++)
        {
            int taskDuration= logs[i][1]-logs[i-1][1];
            if(taskDuration== maxTaskDuration)
                ansId= min(ansId, logs[i][0]);
            if(taskDuration>maxTaskDuration)
                maxTaskDuration= taskDuration,
                ansId= logs[i][0];
        }
        return ansId;
    }
};