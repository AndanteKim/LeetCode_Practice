class TwoSum {
private:
    unordered_map<long, int> freqs;
    unordered_set<int> cache;

public:
    TwoSum() {}
    
    void add(int number) {
        ++freqs[number];
    }
    
    bool find(int value) {
        if (cache.find(value) != cache.end()) return true;

        for (const auto& [elem, f] : freqs){
            if (freqs.find((long)value - elem) != freqs.end())
                if (elem != (value >> 1) || (elem == (value >> 1) && freqs[elem] > 1))
                    return true;
        }

        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */