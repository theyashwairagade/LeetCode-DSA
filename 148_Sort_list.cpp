class Solution {
public:
    ListNode* merge(ListNode* first, ListNode* second)
    {
        ListNode* ans= new ListNode(0);
        ListNode* ansIterator=ans;
        while(first && second)
        {
            bool firstMin=(first->val <= second->val);
            if(firstMin)
            {
                ansIterator->next=first;
                first=first->next;
            }
            else
            {
                ansIterator->next=second;
                second=second->next;
            }
            ansIterator=ansIterator->next;
            ansIterator->next=NULL;
        }
        if(first)
            ansIterator->next=first;
        if(second)
            ansIterator->next=second;
        return ans->next;
    }
    ListNode* mergeSort(ListNode* head,int len)
    {
        if(len<2)   return head;
        
        int mid=len/2;
        ListNode* temp=head;
        for(int i=1;i<mid;i++)
            temp=temp->next;
        ListNode* second= temp->next;
        temp->next=NULL;

        return merge(mergeSort(head,mid),mergeSort(second,len-mid));
    }
    ListNode* sortList(ListNode* head) {
        int len=0;
        for(ListNode* temp= head;temp;temp=temp->next)  len++;
        return mergeSort(head,len);
    }
};