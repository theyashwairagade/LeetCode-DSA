class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> haveToDel;
        for(auto &i: nums)
            haveToDel.insert(i);
        
        ListNode *temp = head;
        while(temp && temp->next){
            if(haveToDel.find(temp->next->val)!=haveToDel.end()){
                temp->next = temp->next->next;
            }
            else
                temp = temp->next;
        }
        
        if(haveToDel.find(head->val)!=haveToDel.end())
            return head->next;
        return head;
    }
};