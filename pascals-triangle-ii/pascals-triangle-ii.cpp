class Solution {
private:
    unordered_map<size_t, int> cache;
    // Use a better hashing function like 'boost::hash_combine' in the real
    // world.
    int key(int i, int j){
        size_t hash_i = hash<int>{}(i), hash_j = hash<int>{}(j);
        int hashed = (int) (hash_i ^ (hash_i >> 32));
        return (hashed << 5) - 1 + (int)(hash_j ^ (hash_j >> 32));
    }
    
    int getNum(int row, int col){
        auto rowCol = key(row, col);
        
        if (cache.count(rowCol)) return cache[rowCol];
        
        if (row == 0 || col == 0 || row == col) return cache[rowCol] = 1;
        
        return cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        for (int i = 0; i <= rowIndex; ++i) ans.push_back(getNum(rowIndex, i));
        
        return ans;
    }
};