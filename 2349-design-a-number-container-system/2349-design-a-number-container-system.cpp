class NumberContainers {
private:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndex;
    unordered_map<int, int> indexToNumber;

public:
    NumberContainers() {}
    
    void change(int index, int number) {
        // Update index to number mapping
        indexToNumber[index] = number;

        // Add index to the min heap for this number
        numberToIndex[number].push(index);
    }
    
    int find(int number) {
        // If number doesn't exist in our map
        if (!numberToIndex.count(number)) return -1;

        // Get reference to min heap for this number
        auto& minHeap = numberToIndex[number];

        // Keep checking top element until we valid index
        while (!minHeap.empty()){
            int index = minHeap.top();

            // If index still maps to our target number, return it.
            if (indexToNumber[index] == number)
                return index;

            // Otherwise remove this tale index
            minHeap.pop();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */