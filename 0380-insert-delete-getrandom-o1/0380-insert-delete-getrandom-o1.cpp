class RandomizedSet {
private:
    unordered_map<int, int> dictionary;
    vector<int> v;
    
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (dictionary.count(val) == 0){
            int idx = v.size();
            dictionary[val] = idx;
            v.push_back(val);
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        if (dictionary.count(val) == 0)
            return false;
        
        int lastElement = v.back(), idx = dictionary[val];
        v[idx] = lastElement;
        dictionary[lastElement] = idx;
        v.pop_back();
        dictionary.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */