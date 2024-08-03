class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        auto curr = head;
        while(curr){
            if(st.find(curr)!=st.end())
                return curr;
            st.insert(curr);
            curr = curr->next;
        }
        return NULL;
    }
};