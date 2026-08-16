class NumMatrix {
private:
    int rows, cols;
    vector<vector<int>> bit;

    int lsb(int n) {
        return n & (-n);
    }

    void updateBit(int r, int c, int val) {
        for (int i = r; i <= rows; i += lsb(i)) {
            for (int j = c; j <= cols; j += lsb(j))
                this -> bit[i][j] += val;
        }
    }

    int queryBit(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= lsb(i)) {
            for (int j = c; j > 0; j -= lsb(j))
                sum += this -> bit[i][j];
        }

        return sum;
    }

    void buildBit(vector<vector<int>>& matrix) {
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int val = matrix[i - 1][j - 1];
                updateBit(i, j, val);
            }
        }
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        if (!rows || !cols) return;

        bit.resize(rows + 1);
        for (int i = 1; i <= rows; ++i) {
            bit[i].resize(cols + 1, 0);
        }

        buildBit(matrix);
    }
    
    void update(int row, int col, int val) {
        int oldVal = sumRegion(row, col, row, col);
        // handling 1-based indexing
        ++row, ++col;
        int diff = val - oldVal;
        updateBit(row, col, diff);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // handling 1-based indexing
        ++row1, ++col1, ++row2, ++col2;
        int a = queryBit(row2, col2);
        int b = queryBit(row1 - 1, col1 - 1);
        int c = queryBit(row2, col1 - 1);
        int d = queryBit(row1 - 1, col2);

        return (a + b) - (c + d);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */