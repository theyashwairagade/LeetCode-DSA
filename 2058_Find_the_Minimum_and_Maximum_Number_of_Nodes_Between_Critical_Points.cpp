class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN}; // {minDistance, maxDistance}
        int minCount = 0, maxCount = 0;
        int prev = head->val;
        bool prevCriticalSectionExist = false;

        for(head = head->next; head && head->next; head= head->next){
            bool maxima = head->val > prev && head->val > head->next->val,
                 minima = head->val < prev && head->val < head->next->val;
            if(maxima || minima){
                if(prevCriticalSectionExist)
                    ans[0] = min(ans[0], minCount),
                    ans[1] = max(ans[1], maxCount);
                else
                    prevCriticalSectionExist = true,
                    maxCount = 0;
                minCount = 0;
            }
            prev = head->val;
            minCount ++,
            maxCount ++;
        }
        if(ans[0]== INT_MAX)
            return {-1, -1};
        return ans;
    }
};