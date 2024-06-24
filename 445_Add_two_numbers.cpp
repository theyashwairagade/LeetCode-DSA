class Solution {
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLinkedList(l1), l2=reverseLinkedList(l2);
        int carry = 0;
        ListNode *ans = new ListNode();

        for(ListNode* current=ans; l1 || l2 || carry;)
        {
            if(l1)
            {
                carry+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                carry+=l2->val;
                l2=l2->next;
            }
            current->next = new ListNode(carry%10);
            current = current->next;
            carry /=10;
        }
        return reverseLinkedList(ans->next);
    }
};