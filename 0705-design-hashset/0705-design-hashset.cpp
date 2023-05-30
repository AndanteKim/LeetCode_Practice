struct Node{
    int value;
    Node* next;
    Node() : value(0), next(nullptr) {}
    Node(int value) : value(value), next(nullptr) {}
    Node(int value, Node* next) : value(value), next(next) {}
};

class Bucket {
private:
    Node* head;

public:
    Bucket(){
        head = new Node(0);
    }
    
    void insert(int newValue){
        if (!exists(newValue)){
            Node* newNode = new Node(newValue, head -> next);
            head -> next = newNode;
        }
    }
    
    void erase(int value){
        Node* prev = head;
        Node* curr = head -> next;
        
        while (curr){
            if (curr -> value == value){
                prev -> next = curr -> next;
                return;
            }
            prev = curr;
            curr = curr -> next;
        }
    }
    
    bool exists(int value){
        Node* curr = head -> next;
        while (curr){
            if (curr -> value == value) return true;
            curr = curr -> next;
        }
        
        return false;
    }
};

class MyHashSet {
private:
    int keyRange;
    vector<Bucket*> bucketArray;
protected:
    int hash(int key){
        return key % keyRange;
    }
public:
    MyHashSet() {
        keyRange = 769;
        Bucket* bucket = new Bucket();
        for (int i = 0; i < 769; ++i) bucketArray.push_back(bucket);
    }
    
    void add(int key) {
        int bucketIndex = hash(key);
        bucketArray[bucketIndex] -> insert(key);
    }
    
    void remove(int key) {
        int bucketIndex = hash(key);
        bucketArray[bucketIndex] -> erase(key);
    }
    
    bool contains(int key) {
        int bucketIndex = hash(key);
        return bucketArray[bucketIndex] -> exists(key);
    }
};




/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */