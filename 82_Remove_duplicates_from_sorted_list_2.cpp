class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        head=new ListNode(0,head);
        ListNode *curr=head;
        while(curr && curr->next && curr->next->next)
        {
            if(curr->next->val!=curr->next->next->val)
            {
                curr=curr->next;
                continue;
            }
            int temp=curr->next->val;
            while(curr->next && curr->next->val==temp)
                curr->next=curr->next->next;
        }
        return head->next;
    }
};