class NumberContainers {
private:
    unordered_map<int, set<int>> numberToIndices;
    unordered_map<int, int> indexToNumber;

public:
    // Constructor
    // The data structures are already initialized as
    // part of the member variable declarations
    NumberContainers() {}
    
    void change(int index, int number) {
        if (indexToNumber.count(index)){
            if (indexToNumber[index] != number){
                int prevNumber = indexToNumber[index];
                numberToIndices[prevNumber].erase(index);

                if (numberToIndices[prevNumber].size() == 0)
                    numberToIndices.erase(prevNumber);
            }
        }

        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.count(number))
            // Get the smallest index
            return *numberToIndices[number].begin();

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */