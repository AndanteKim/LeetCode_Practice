class UnionFind{
private:
    vector<int> parent, islandSize;

public:
    // Constructo to initialize DSU with 'n' elements
    UnionFind(int n){
        parent.resize(n);
        // Each node is its own parent initially with size 1
        iota(parent.begin(), parent.end(), 0);
        islandSize.resize(n, 1);
    }

    // Function to find the root of a node with path compression
    int find(int node){
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    // Function to union two sets based on size
    void unite(int node1, int node2){
        int root1 = find(node1), root2 = find(node2);

        // Already in the same set
        if (root1 == root2) return;

        // Union by size: Attach the smaller island to the larger one
        if (islandSize[root1] < islandSize[root2]){
            // Attach root1 to root2
            parent[root1] = root2;

            // Update size of root2's island
            islandSize[root2] += islandSize[root1];
        }
        else{
            //Attach root2 to root1
            parent[root2] = root1;

            // Update size of rootA's island
            islandSize[root1] += islandSize[root2];
        }
    }

    int getIslandSize(int root){
        return islandSize[root];
    }
};

class Solution {
private:
    int m, n;

    // Direction vectors for traversing up, down, left, and right
    const vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool isValid(int i, int j, vector<vector<int>>& grid){
        return 0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();

        // Initialize DSU for the entire grid
        UnionFind *uf = new UnionFind(m * n);

        // Step 1: Union adjacent 1's in the grid
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col]){
                    // Flatten 2D index to 1D
                    int currNode = row * n + col;

                    for (const auto& [dr, dc] : dirs){
                        int nextR = row + dr, nextC = col + dc;

                        // Check bounds and ensure the neighbor is also '1'
                        if (isValid(nextR, nextC, grid)){
                            int neighborNode = nextR * n + nextC;
                            uf -> unite(currNode, neighborNode);
                        }
                    }

                }
            }
        }

        // Step 2: Calculate the maximum possible island size
        int maxIslandSize = 0;

        // Flag to check if there are any zeros in the grid
        bool hasZero = false;

        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] == 0){
                    hasZero = true;

                    // Start with the flipped '0'
                    int currIslandSize = 1;

                    // To store unique roots for a '0' neighbors
                    unordered_set<int> uniqueIsland;

                    for (const auto& [dr, dc] : dirs){
                        int nextR = row + dr, nextC = col + dc;

                        // Check bounds and ensure the neighbor is '1'
                        if (isValid(nextR, nextC, grid)){
                            int rootIsland = uf -> find(nextR * n + nextC);
                            uniqueIsland.insert(rootIsland);
                        }
                    }

                    // Sum up the sizes of unique neighboring islands
                    for (int island : uniqueIsland)
                        currIslandSize += uf -> getIslandSize(island);
                    
                    // Update the result with the largest island size found
                    maxIslandSize = max(maxIslandSize, currIslandSize);
                }
            }
        }

        // If there are no zeros, the largest island is the entire grid
        return hasZero? maxIslandSize : m * n;
    }
};