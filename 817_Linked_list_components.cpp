class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        bool component=false;
        int totalComponents=0;
        for(ListNode* temp = new ListNode(*head);temp;temp=temp->next)
        {
            auto it = find(nums.begin(), nums.end(), temp->val);
            if (it == nums.end()) component=false;
            else    if(!component)
            {
                totalComponents++;
                component=true;
            }  
        }
        return totalComponents;
    }
};