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
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* ptr = head;
        
        while (ptr){
            Node* newOne = new Node(ptr -> val, nullptr, nullptr);
            newOne -> next = ptr -> next;
            ptr -> next = newOne;
            ptr = newOne -> next;
        }
        
        ptr = head;
        while (ptr){
            ptr -> next -> random = ptr -> random? ptr -> random -> next : nullptr;
            ptr = ptr -> next -> next;
        }
        
        Node* oldOne = head, * newOne = head -> next, * headNew = head -> next;
        
        while (oldOne){
            oldOne -> next = oldOne -> next -> next;
            newOne -> next = newOne -> next? newOne -> next -> next : nullptr;
            oldOne = oldOne -> next;
            newOne = newOne -> next;
        }
        
        return headNew;
    }
};