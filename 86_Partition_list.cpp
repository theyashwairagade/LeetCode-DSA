// Brutte Force by space complexity of O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return head;
        ListNode *left=NULL, *right=NULL, *leftCurr=NULL, *rightCurr=NULL;
        for(ListNode *curr=head;curr;curr=curr->next)
            if(curr->val<x)
                if(leftCurr)
                    leftCurr=leftCurr->next=new ListNode(curr->val);
                else
                    leftCurr=left= new ListNode(curr->val);
            else
                if(rightCurr)
                    rightCurr=rightCurr->next=new ListNode(curr->val);
                else
                    rightCurr=right= new ListNode(curr->val);
        if(!leftCurr)   return right;
        leftCurr->next=right;
        return left;
    }
};

// More optimal with space complexity of O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return head;
        ListNode *left=NULL, *right=NULL, *leftCurr=NULL, *rightCurr=NULL;
        for(ListNode *curr=head;curr;curr=curr->next)
            if(curr->val<x)
                if(leftCurr)
                    leftCurr=leftCurr->next=curr;
                else
                    leftCurr=left=curr;
            else
                if(rightCurr)
                    rightCurr=rightCurr->next=curr;
                else
                    rightCurr=right=curr;
        if(rightCurr)
            rightCurr->next=NULL; // Just added this line and problem solved
        if(!leftCurr)   return right;
        leftCurr->next=right;
        return left;
    }
};