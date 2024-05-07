class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> old_to_new;
        // Creating Unordered map
        for(Node* curr = head;curr;curr = curr->next)
            old_to_new[curr] = new Node(curr->val);
        // Using unordered map
        for(Node* curr = head;curr;curr = curr->next)
            old_to_new[curr]->next = old_to_new[curr->next],
            old_to_new[curr]->random = old_to_new[curr->random];
        return old_to_new[head];
    }
};

// Later focus on interweaving nodes solution