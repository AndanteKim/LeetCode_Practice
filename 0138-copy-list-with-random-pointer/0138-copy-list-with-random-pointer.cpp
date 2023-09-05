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
    Node* getClonedNode(Node* node){
        if (node){
            if (visitedHash.find(node) != visitedHash.end())
                return visitedHash[node];
            else{
                visitedHash[node] = new Node(node -> val, nullptr, nullptr);
                return visitedHash[node];
            }
        }
        
        return nullptr;
    }
    
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* oldOne = head;
        Node* newOne = new Node(oldOne -> val, nullptr, nullptr);
        visitedHash[oldOne] = newOne;
        
        while (oldOne){
            newOne -> next = getClonedNode(oldOne -> next);
            newOne -> random = getClonedNode(oldOne -> random);
            
            // move to one next step
            oldOne = oldOne -> next;
            newOne = newOne -> next;
        }
        
        return visitedHash[head];
    }
};