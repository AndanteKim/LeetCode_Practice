/*
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        // base case
        if (!root) return root;
        
        // BFS straightforward
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()){
            int sz = q.size();
            Node* prev = nullptr;
            for (int i = 0; i < sz; ++i){
                Node* curr = q.front(); q.pop();
                
                // connect next pointer
                if (prev)
                    prev -> next = curr;
                
                // move on to the next pointer
                prev = curr;
                
                if (curr -> left)
                    q.push(curr -> left);
                
                if (curr -> right)
                    q.push(curr -> right);
            }
            
        }
        
        return root;
    }
};