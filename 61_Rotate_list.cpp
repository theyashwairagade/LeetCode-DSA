class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) // Edge cases: empty list or no rotation needed
            return head;

        ListNode* curr = head;
        int len = 1; // Initialize to 1 since we're already at head

        while (curr->next) { // Calculate the length of the list
            len++;
            curr = curr->next;
        }

        k = k % len; // Reduce k if it's greater than the length of the list
        if (k == 0)   // If k is now 0, no rotation needed
            return head;

        curr->next = head; // Make the list circular

        int stepsToNewHead = len - k; // Calculate steps to the new head

        curr = head;
        while (--stepsToNewHead > 0) { // Move curr to the node just before the new head
            curr = curr->next;
        }

        ListNode* newHead = curr->next; // New head
        curr->next = nullptr; // Break the circular list

        return newHead;
    }
};
