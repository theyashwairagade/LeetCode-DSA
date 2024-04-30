// Brutte force
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode*temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        n=len-n;
        if(!n)    return head->next;
        temp=head;
        n--;
        while(n--)  temp=temp->next;
        temp->next=temp->next->next;
        return head;
    }
};


// More optimal as removed len and compressed the code
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        for(n=(-n);temp;n++)    temp=temp->next;
        if(!n)    return head->next;
        temp=head;
        for(n--;n--;temp=temp->next);
        temp->next=temp->next->next;
        return head;
    }
};


// Most optimal as won't need to traverse linked list twice
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i)    first = first->next;

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;
    }
};