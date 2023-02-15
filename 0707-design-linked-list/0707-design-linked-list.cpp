class MyLinkedList {
    struct Node{
        int val;
        Node *next, *prev;
        Node(int x) {
            val = x;
            next = prev = nullptr;
        }
    };
    
    
    int sz;
    Node *head, *tail;
public:
    MyLinkedList() {
        sz = 0;
        head = new Node(0);
        tail = new Node(0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        Node *curr;
        if (index + 1 < sz - index){
            curr = head;
            for (int i = 0; i <= index; ++i) curr = curr -> next;
        }
        else{
            curr = tail;
            for (int i = 0; i < sz - index; ++i) curr = curr -> prev;
        }
        return curr -> val;
    }
    
    void addAtHead(int val) {
        Node *pred = head, *succ = head -> next;
        ++sz;
        Node* to_add = new Node(val);
        to_add -> prev = pred;
        to_add -> next = succ;
        pred -> next = to_add;
        succ -> prev = to_add;
    }
    
    void addAtTail(int val) {
        Node *succ = tail, *pred = tail -> prev;
        ++sz;
        Node* to_add = new Node(val);
        to_add -> prev = pred;
        to_add -> next = succ;
        pred -> next = to_add;
        succ -> prev = to_add;
    }
    
    void addAtIndex(int index, int val) {
        if (index > sz) return;
        if (index < 0) index = 0;
        Node *pred, *succ;
        if (index < sz - index) {
            pred = head;
            for (int i = 0; i < index; ++i) pred = pred -> next;
            succ = pred -> next;
        }
        else{
            succ = tail;
            for (int i = 0; i < sz - index; ++i) succ = succ -> prev;
            pred = succ -> prev;
        }
        
        ++sz;
        Node *to_add = new Node(val);
        to_add -> prev = pred;
        to_add -> next = succ;
        pred -> next = to_add;
        succ -> prev = to_add;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) return;
        
        Node *pred, *succ;
        if (index < sz - index){
            pred = head;
            for (int i = 0; i < index; ++i) pred = pred -> next;
            succ = pred -> next -> next;
        }
        else{
            succ = tail;
            for (int i = 0; i < sz - index - 1; ++i) succ = succ -> prev;
            pred = succ -> prev -> prev;
        }
        --sz;
        pred -> next = succ;
        succ -> prev = pred;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */