class MyHashSet {
private:
    vector<int> dict;
    
public:
    MyHashSet() {
        dict.resize(pow(10, 6) + 1, 0);
    }
    
    void add(int key) {
        if (dict[key] == 0) ++dict[key];
    }
    
    void remove(int key) {
        if (dict[key] > 0) --dict[key];
    }
    
    bool contains(int key) {
        return dict[key] > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */