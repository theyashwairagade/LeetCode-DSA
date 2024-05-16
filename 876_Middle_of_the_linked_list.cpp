class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            head=head->next;
            fast=fast->next->next;
        }
        return head;
    }
};