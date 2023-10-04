class MyHashMap {
private:
    vector<int> dictionary;
    
public:
    MyHashMap() {
        dictionary.resize(1'000'001, -1);
    }
    
    void put(int key, int value) {
        dictionary[key] = value;
    }
    
    int get(int key) {
        return dictionary[key];
    }
    
    void remove(int key) {
        dictionary[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */