class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = nullptr, *temp = nullptr;
        int currentCount = 0;

        while (head) 
        {
            if (head->val == 0) 
            {
                if (newHead == nullptr) 
                    temp = newHead = new ListNode(currentCount);
                else 
                    temp = temp->next = new ListNode(currentCount);
                currentCount = 0;
            }else   currentCount += head->val;
            head = head->next;
        }

        if (currentCount > 0) 
            if (newHead == nullptr) 
                newHead = new ListNode(currentCount);
            else 
                temp->next = new ListNode(currentCount);

        return newHead->next;
    }
};
