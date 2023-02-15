class MyLinkedList {
    int sz;
    ListNode *head;
public:
    MyLinkedList() {
        sz = 0;
        head = new ListNode(0);
        
    }
    
    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        ListNode *curr = head;
        
        for (int _ = 0; _ <= index; ++_) curr = curr -> next;
        return curr -> val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(sz, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > this -> sz) return;
        if (index < 0) index = 0;
        ++sz;
        ListNode* pred = head;
        for (int i = 0; i < index; ++i) pred = pred -> next;
        ListNode* to_add = new ListNode(val);
        to_add -> next = pred -> next;
        pred -> next = to_add;
        
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) return;
        --sz;
        ListNode *pred = head;
        for (int i = 0; i < index; ++i) pred = pred -> next;
        pred -> next = pred -> next -> next;
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