class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode();
        ListNode* temp = Head;
        int sum = 0;
        while (l1 || l2 || sum) //Waoo
        {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(sum % 10);
            sum /=10;
            temp = temp->next;
        }
        return Head->next;
    }
};