class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prevRow = triangle[0];

        for (int row = 1; row < triangle.size(); ++row){
            vector<int> currRow{};
            for (int col = 0; col < triangle[row].size(); ++col){
                int smallest = std::numeric_limits<int>::max();
                if (col > 0) smallest = prevRow[col - 1];
                if (col < row) smallest = min(smallest, prevRow[col]);

                currRow.push_back(triangle[row][col] + smallest);
            }

            prevRow = currRow;
        }

        return *min_element(prevRow.begin(), prevRow.end());
    }
};