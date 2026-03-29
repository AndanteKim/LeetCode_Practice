class PhoneDirectory {
private:
    unordered_set<int> isAvailable;

public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) isAvailable.insert(i);
    }
    
    int get() {
        if (isAvailable.empty()) return -1;

        int ans = *isAvailable.begin();
        isAvailable.erase(ans);
        return ans;
    }
    
    bool check(int number) {
        return isAvailable.contains(number);
    }
    
    void release(int number) {
        isAvailable.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */