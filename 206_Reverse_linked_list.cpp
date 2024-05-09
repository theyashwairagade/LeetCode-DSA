// try once by self
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode*prev=NULL,*current=head;
        while(current!=NULL)
        {
            ListNode*nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }
        return prev;
    }
};