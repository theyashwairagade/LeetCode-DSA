class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy= new ListNode(0,head);
        ListNode* leftPrev=dummy, *cur=head;
        for(int i=1;i<left;i++)
            leftPrev=cur,cur=cur->next;
        ListNode* prev=NULL;
        for(int i=0;i<=right-left;i++)
        {
            ListNode* tempNext=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tempNext;
        }
        leftPrev->next->next=cur;
        leftPrev->next=prev;
        return dummy->next;
    }
};