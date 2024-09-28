class MyCircularDeque {
private:
    struct Node{
        int val;
        Node* prev;
        Node* next;
        Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next){}
    };
    
    int length, size;
    Node *head, *tail; 
    
public:
    MyCircularDeque(int k) {
        // Create a double linked list
        length = k;
        size = 0;
        head = nullptr;
        tail = head;
    }
    
    bool insertFront(int value) {
        // Base case: If the size is already full
        if (isFull()) return false;
        
        // Insert the front depending on the length
        if (!head){
            head = new Node(value, nullptr, nullptr);
            tail = head;
        }
        else{
            Node* newNode = new Node(value, nullptr, head);
            head -> prev = newNode;
            head = newNode;
        }
        
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        // Base case: If the size is already full
        if (isFull()) return false;
        
        // Insert the tail depending on the length
        if (!tail){
            tail = new Node(value, nullptr, nullptr);
            head = tail;
        }
        else{
            Node* newNode = new Node(value, tail, nullptr);
            tail -> next = newNode;
            tail = newNode;
        }
        
        ++size;
        return true;
    }
    
    bool deleteFront() {
        // Base case: If it's empty
        if (isEmpty()) return false;
        
        // Delete the head depending on the length
        Node* node = head;
        if (size == 1){
            head = nullptr;
            tail = head;
        }
        else
            head = head -> next;
        
        
        delete node;
        --size;
        return true;
    }
    
    bool deleteLast() {
        // Base case: If it's empty
        if (isEmpty()) return false;
        
        // Delete the tail depending on the length
        Node* node = tail;
        if (size == 1){
            head = nullptr;
            tail = head;
        }
        else
            tail = tail -> prev;
        
        delete node;
        --size;
        return true;
    }
    
    int getFront() {
        return isEmpty()? -1 : head -> val;
    }
    
    int getRear() {
        return isEmpty()? -1 : tail -> val;
    }
    
    bool isEmpty() {
        return (size == 0)? true : false;
    }
    
    bool isFull() {
        return (size == length)? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */