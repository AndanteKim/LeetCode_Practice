class Node{
private:
    int freq;
    Node *prev, *next;
    unordered_set<string> words;
    friend class AllOne;
    
public:
    Node(int freq): freq(freq), prev(nullptr), next(nullptr){
    }
};

class AllOne {
private:
    // Set dummy nodes as head and tail
    Node* head, *tail;
    // Mapping from key to its node
    unordered_map<string, Node*> mapping;
    
public:
    // Intialize head, tail with linking them each other
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    // Insert a new key with value 1 or increment an existing key by 1.
    void inc(string key) {
        if (!mapping.count(key)){
            Node* nextNode = head -> next;
            if (nextNode == tail || nextNode -> freq > 1){
                // Create a new node
                Node* newNode = new Node(1);
                head -> next = newNode;
                newNode -> next = nextNode;
                newNode -> prev = head;
                nextNode -> prev = newNode;
                newNode -> words.insert(key);
                mapping[key] = newNode;
            }
            else{
                nextNode -> words.insert(key);
                mapping[key] = nextNode;
            }
        }
        else{
            Node* nextNode = mapping[key] -> next, *node = mapping[key];
            int freq = mapping[key] -> freq;
            node -> words.erase(key);   // Remove key from current node
            mapping.erase(key);
            if (nextNode == tail || nextNode -> freq != freq + 1){
                // Create a new node if next node doesn't exist or freq is not freq + 1.
                Node* newNode = new Node(freq + 1);
                newNode -> words.insert(key);
                node -> next = newNode;
                newNode -> next = nextNode;
                nextNode -> prev = newNode;
                newNode -> prev = node;
                mapping[key] = newNode;
            }
            else{
                // Increment the existing next node
                nextNode -> words.insert(key);
                mapping[key] = nextNode;
            }
            
            // Remove the current node if it has no keys left
            if (node -> words.size() == 0) deleteNode(node);
        }
    }
    
    // Decrements an existing key by 1. If key's value is 1, remove it from the data structure.
    void dec(string key) {
        if (!mapping.count(key)) return;    // Key doesn't exist
        
        Node* node = mapping[key], *prevNode = node -> prev;
        int freq = node -> freq;
        node -> words.erase(key);
        if (freq == 1){
            // Remove the key from the map if freq is 1.
            mapping.erase(key);
        }
        else if (prevNode == head || prevNode -> freq != freq - 1){
            Node* newNode = new Node(freq - 1);
            prevNode -> next = newNode;
            newNode -> next = node;
            node -> prev = newNode;
            newNode -> prev = prevNode;
            newNode -> words.insert(key);
            mapping[key] = newNode;
        }
        else{
            // Decrement the existing previous node
            prevNode -> words.insert(key);
            mapping[key] = prevNode;
        }
        
        // Remove the node if it has no keys left
        if (node -> words.size() == 0)
            deleteNode(node);
    }
    
    // Return one of the keys with maximal value.
    string getMaxKey() {
        if (tail -> prev == head) return "";    // No keys exist;
        
        // Return one of the keys from the tail's previous node
        return *(tail -> prev -> words.begin());
    }
    
    string getMinKey() {
        if (head -> next == tail) return "";    // No keys exist
        
        return *(head -> next -> words.begin());    // Return one of the keys from the head's next node.
    }
    
    void deleteNode(Node* node){
        Node* prevNode = node -> prev, *nextNode = node -> next;
        
        // delete the current node and link
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        delete node;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */