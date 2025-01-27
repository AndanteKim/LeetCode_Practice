typedef long long ll;
class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n){
        // Initialize all cells as individual components
        parent.resize(n * n, -1);
        rank.resize(n * n, 1);
    }

    int find(int index){
        // Find with path compression for better performance
        if (parent[index] == -1)
            return index;

        return parent[index] = find(parent[index]);
    }

    void merge(int index1, int index2){
        // Union by linking roots directly
        int root1 = find(index1), root2 = find(index2);

        // Already in same component
        if (root1 == root2) return;

        // Make the root with the higher rank the parent of the other root
        if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else{
            parent[root2] = root1;
            ++rank[root1];
        }
    }
};


class Solution {
private:
    int n;

    // Direction arrays for moving up, down, left, right
    const vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool isValid(int row, int col, vector<vector<int>>& grid){
        return 0 <= row && row < n && 0 <= col && col < n && grid[row][col] != -1;
    }

    int getIndex(int row, int col){
        return n * row + col;
    }

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        this -> n = grid.size();
        
        // Initialize Union-Find data structure with size n * n
        UnionFind *uf = new UnionFind(n);

        // First pass: Connect all adjacent non-blocked cells into components
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < n; ++col){
                // Skip blocked cells
                if (grid[row][col] == -1) continue;
                
                // For each valid cell, check all 4 adjacent cells
                for (const auto& [di, dj] : dirs){
                    int newRow = row + di, newCol = col + dj;

                    // If adjacent cell is valid, connect it to current cell
                    if (isValid(newRow, newCol, grid))
                        // Convert 2D coordinates to 1D index and union them
                        uf -> merge(getIndex(row, col), getIndex(newRow, newCol));
                }
            }
        }

        // Second pass: Calculate sum of values in each connected component
        unordered_map<int, ll> compSum; // Maps component root to its sum
        ll totalSum = 0;
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] == -1) continue;

                // Find the root of current cell's component
                int parent = uf -> find(getIndex(row, col));

                // Add current cell's value to its component sum
                compSum[parent] = compSum[parent] + grid[row][col];
                totalSum += grid[row][col];
            }
        }

        // Third pass: Calculate remoteness sum
        // For each cell, remoteness = (totalSum - sum of its component)
        ll ans = 0;
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] != -1)
                    ans += totalSum - compSum[uf -> find(getIndex(row, col))];
            }
        }
        
        return ans;
    }
};