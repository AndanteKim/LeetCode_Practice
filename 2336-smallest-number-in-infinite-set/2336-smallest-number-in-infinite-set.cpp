class SmallestInfiniteSet {
    unordered_set<int> isPresent;
    priority_queue<int, vector<int>, greater<int>> addedIntegers;
    int currentInteger;
    
public:
    SmallestInfiniteSet() {
        currentInteger = 1;
    }
    
    int popSmallest() {
        int ans;
        if(!addedIntegers.empty()){
            ans = addedIntegers.top();
            isPresent.erase(ans);
            addedIntegers.pop();
        }
        else{
            ans = currentInteger;
            ++currentInteger;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (currentInteger <= num || isPresent.find(num) != isPresent.end()) return;
        addedIntegers.push(num);
        isPresent.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */