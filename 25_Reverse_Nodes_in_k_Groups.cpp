class Solution {
    int lenOfLinkedList(ListNode* head){
        int n = 0;
        while(head)
            n++,
            head = head->next;
        return n;
    }
    ListNode* reverseLinkedList(ListNode* head, int &k, int &n) {
        if(n<k)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i = 0; i<k; i++, n--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseLinkedList(curr, k, n);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = lenOfLinkedList(head);
        return reverseLinkedList(head, k, n);
    }
};