// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// Using BFS
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* prev=NULL;
        while(q.size()>1)
        {
            Node* tp=q.front();
            if(tp)
            {
                tp->next=prev;
                if(tp->right)   q.push(tp->right);
                if(tp->left)    q.push(tp->left);
            }else   q.push(NULL);    
            prev=tp;
            q.pop();
        }
        return root;
    }
};