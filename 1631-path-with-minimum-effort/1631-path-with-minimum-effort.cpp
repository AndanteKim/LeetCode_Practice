class Edge{
public:
    int x, y, diff;
    
    Edge(int x, int y, int diff){
        this -> x = x;
        this -> y = y;
        this -> diff = diff;
    }
    
};

class UnionFind{
public:
    vector<int> parent, rank;
    vector<Edge> edgeList;

    UnionFind(vector<vector<int>>& heights){
        int row = heights.size(), col = heights[0].size();
        parent.assign(row * col, 0);
        rank.assign(row * col, 0);
        
        for (int currRow = 0; currRow < row; ++currRow){
            for (int currCol = 0; currCol < col; ++currCol){
                if (currRow > 0){
                    edgeList.push_back(Edge(currRow * col + currCol, (currRow - 1) * col + currCol, abs(heights[currRow][currCol] - heights[currRow - 1][currCol])));
                }
                if (currCol > 0){
                    edgeList.push_back(Edge(currRow * col + currCol, currRow * col + currCol - 1, abs(heights[currRow][currCol] - heights[currRow][currCol - 1])));
                }
                
                parent[currRow * col + currCol] = currRow * col + currCol;
            }
        }
    }
    
    int find(int i){
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    void UnionSet(int x, int y){
        int parentX = find(x), parentY = find(y);
        if (parentX != parentY){
            if (rank[parentX] > rank[parentY]) parent[parentY] = parentX;
            else if (rank[parentX] < rank[parentY]) parent[parentX] = parentY;
            else{
                parent[parentY] = parentX;
                ++rank[parentX];
            }
        }
    }
};

class Solution {
    static bool compareInterval(const Edge& p1, const Edge& p2){
    return (p1.diff < p2.diff);
}

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        if (row == 1 && col == 1) return 0;
        UnionFind unionFind(heights);
        vector<Edge> edgeList = unionFind.edgeList;
        sort(edgeList.begin(), edgeList.end(), compareInterval);
        
        for (int i = 0; i < edgeList.size(); ++i){
            int x = edgeList[i].x, y = edgeList[i].y;
            unionFind.UnionSet(x, y);
            if (unionFind.find(0) == unionFind.find(row * col - 1)) return edgeList[i].diff;
        }
        
        return -1;
    }
};