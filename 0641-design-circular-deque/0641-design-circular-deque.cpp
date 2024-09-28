class MyCircularDeque {
private:
    int length, size, head, tail;
    vector<int> deque;
    
public:
    MyCircularDeque(int k) {
        length = k, size = 0;
        deque.resize(k);
        head = 0, tail = k - 1;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        
        head = (head - 1 + length) % length;
        deque[head] = value;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        
        tail = (tail + 1) % length;
        deque[tail] = value;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % length;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail - 1 + length) % length;
        --size;
        return true;
    }
    
    int getFront() {
        return isEmpty()? -1 : deque[head];
    }
    
    int getRear() {
        return isEmpty()? -1 : deque[tail];
    }
    
    bool isEmpty() {
        return size == 0? true : false;
    }
    
    bool isFull() {
        return size == length? true : false;
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