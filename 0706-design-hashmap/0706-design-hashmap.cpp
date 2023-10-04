class LinkedList{
public:
    int key, val;
    LinkedList* next;
    LinkedList(): key(-1), val(-1), next(nullptr){}
    LinkedList(int key, int val): key(key), val(val), next(nullptr){}
    LinkedList(int key, int val, LinkedList* next): key(key), val(val), next(next){}
};

class MyHashMap {
private:
    int keySpace = 2069;
    vector<LinkedList*> hashTable;
    
public:
    MyHashMap() {
        hashTable.resize(keySpace, new LinkedList());
    }
    
    int getHashKey(int key){
        return key % keySpace;
    }
    
    void put(int key, int value) {
        LinkedList *curr = hashTable[getHashKey(key)];
        
        while (curr -> next){
            if (curr -> next -> key == key){
                curr -> next -> val = value;
                return;
            }
            curr = curr -> next;
        }
        curr -> next = new LinkedList(key, value);
    }
    
    int get(int key) {
        LinkedList* curr = hashTable[getHashKey(key)] -> next;
        
        while (curr){
            if (curr -> key == key){
                return curr -> val;
            }
            curr = curr -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        LinkedList* curr = hashTable[getHashKey(key)];
        while (curr && curr -> next){
            if (curr -> next -> key == key){
                curr -> next = curr -> next -> next;
                return;
            }
            curr = curr -> next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */