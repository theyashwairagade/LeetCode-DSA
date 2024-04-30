class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)  return list2; // Optimization
        if(!list2)  return list1; // Optimization
        ListNode* ans= NULL;
        ListNode* head=ans;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                if(head) {
                    head->next=new ListNode(list1->val);
                    head=head->next;
                }
                else    head=ans=new ListNode(list1->val);
                list1=list1->next;
            }else
            {
                if(head) {
                    head->next=new ListNode(list2->val);
                    head=head->next;
                }
                else    head=ans=new ListNode(list2->val);
                list2=list2->next;
            }
        }
        while(list1)
        {
            head->next=new ListNode(list1->val);
            head=head->next;
            list1=list1->next;
        }
        while(list2)
        {
            head->next=new ListNode(list2->val);
            head=head->next;
            list2=list2->next;
        }
        return ans;
    }
};


// Later try for space complexity of O(1)