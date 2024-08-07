class UnionFind{
private:
    vector<int> parent, rank;
    int count;
    
public:
    UnionFind(int n){
        this -> count = n;
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    void disjoint(int x, int y){
        int rootX = find(x), rootY= find(y);
        
        if (rootX != rootY){
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else{
                parent[rootY] = rootX;
                ++rank[rootX];
            }
            --count;
        }
    }
    
    int getCount(){
        return count;
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        
        int m = board.size(), n = board[0].size();
        UnionFind uf = UnionFind(m * n + 1);
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                // If 'O' node is on the boundry, connect it to the dummy node
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1 && board[i][j] == 'O')
                    uf.disjoint(i * n + j, m * n);
                // Connect 'O' node to its neighbor 'O' nodes
                else if (board[i][j] == 'O'){
                    if (board[i - 1][j] == 'O')
                        uf.disjoint(i * n + j, (i - 1) * n + j);
                    
                    if (board[i + 1][j] == 'O')
                        uf.disjoint(i * n + j, (i + 1) * n + j);
                    
                    if (board[i][j - 1] == 'O')
                        uf.disjoint(i * n + j, i * n + j - 1);
                    
                    if (board[i][j + 1] == 'O')
                        uf.disjoint(i * n + j, i * n + j + 1);
                }
            }
        }
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                // If a 'O' node is not connected to the dummy node, it's captured.
                if (!uf.connected(i * n + j, m * n))
                    board[i][j] = 'X';
        }
    }
};