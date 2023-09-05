/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> visitedHash;
    
public:
    Node* copyRandomList(Node* head) {
        // base case
        if (!head) return nullptr;
        
        
        if (visitedHash.find(head) != visitedHash.end())
            return visitedHash[head];
            
        // create a new node
        Node* node = new Node(head -> val, nullptr, nullptr);
        
        // save it in the hash map
        visitedHash[head] = node;
        
        // recursively copy the remaining linked list starting once from
        // the next pointer and then from the random pointer
        // update two independent recursive calls
        node -> next = copyRandomList(head -> next);
        node -> random = copyRandomList(head -> random);
        
        return node;
    }
};