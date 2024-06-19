class UnionFind{
private:
    unordered_map<int, int> root, rank, size;
    
    int find(int x){
        if (root[x] != x)
            root[x] = find(root[x]);
        return root[x];
    }
    
    void unionSet(int x, int y){
        int rootX = find(x), rootY = find(y);
        if (rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        else if (rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        else{
            root[rootY] = rootX;
            ++rank[rootX];
            size[rootX] += size[rootY];
        }
    }

public:
    UnionFind(vector<int>& nums){
        for (int num : nums){
            root[num] = num;
            rank[num] = 0;
            size[num] = 1;
        }
    }
    
    void unionSets(void){
        for (const auto& num : root){
            if (root.find(num.first + 1) != root.end())
                unionSet(num.first, num.first + 1);
        }
    }
    
    int getMaxsize(void){
        int maxSize = 0;
        for (const auto& sz : size)
            maxSize = max(maxSize, sz.second);
        
        return maxSize;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        Each num is initially an island, we want to find out
        the largest continent -> Disjoint Set
        1. Build disjoint set for each num.
        2. Try connect each set with its consecutive number
        3. Return the largest set size
        
        Complexity:
        - time: O(n * alpha(n)) where n is the size of nums
        - space: O(n)
        */
        
        UnionFind uf(nums);     // O(n)
        uf.unionSets();         // O(n * alpha(n))
        return uf.getMaxsize();
    }
};