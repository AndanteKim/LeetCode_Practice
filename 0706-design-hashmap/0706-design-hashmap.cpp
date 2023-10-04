class Bucket{
private:
    vector<pair<int, int>> bucket;
    
public:
    Bucket(){}
    
    int get(int key){
        for (auto& [k, v] : bucket){
            if (k == key)
                return v;
        }
        
        return -1;
    }
    
    void update(int key, int val){
        bool found = false;
        for (int i = 0; i < bucket.size(); ++i){
            if (key == bucket[i].first){
                bucket[i] = make_pair(key, val);
                found = true;
                break;
            }
        }
        
        if (!found) bucket.push_back(make_pair(key, val));
    }
    
    void remove(int key){
        int target = -1;
        for (int i = 0; i < bucket.size(); ++i){
            if (bucket[i].first == key)
                target = i;
        }
        
        if (target != -1)
            bucket.erase(bucket.begin() + target);
    }
};

class MyHashMap {
private:
    int keySpace = 2069;
    vector<Bucket*> hashTable;
    
public:
    MyHashMap() {
        hashTable.resize(keySpace, new Bucket());
    }
    
    void put(int key, int value) {
        int hashKey = key % keySpace;
        hashTable[hashKey] -> update(key, value);
    }
    
    int get(int key) {
        int hashKey = key % keySpace;
        return hashTable[hashKey] -> get(key);
    }
    
    void remove(int key) {
        int hashKey = key % keySpace;
        hashTable[hashKey] -> remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */