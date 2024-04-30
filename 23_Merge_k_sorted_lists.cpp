// Brutte Force by me with time complexity of O(n square) and space complexity of O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        int n=lists.size();
        for(int i=0;i<n;)
        {
            if(lists[i])    i++;
            else    lists.erase(lists.begin()+i),n--; //time complexity of O(n)
        }
        while(n)
        {
            int minIndex=0;
            for(int i=0;i<n;i++) //time complexity of O(n)
                if(lists[i]->val<lists[minIndex]->val)  minIndex=i;
            
            // cout<<"minIndex= "<<minIndex;
            temp->next=lists[minIndex];
            lists[minIndex]=lists[minIndex]->next;
            temp=temp->next;
            temp->next=NULL;
            if(!lists[minIndex])    lists.erase(lists.begin()+minIndex),n--; //time complexity of O(n)
        }
        return head->next;
    }
};





// More optimized as used heap data structure by time complexity of O(nklogk) and space complexity of O(1)
class Solution {
public:
    struct customComparator {
        bool operator()(const ListNode* a, const ListNode* b) const {
            if (!a) return false;
            if (!b) return true;
            return a->val > b->val; // Change to > for min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        priority_queue<ListNode*, vector<ListNode*>, customComparator> minHeap;
        for (const auto &list : lists)
            if (list) minHeap.push(list);

        while (!minHeap.empty()) {
            temp->next = minHeap.top();
            temp = temp->next;
            minHeap.pop();
            if (temp->next) minHeap.push(temp->next);
        }
        return head->next;
    }
};