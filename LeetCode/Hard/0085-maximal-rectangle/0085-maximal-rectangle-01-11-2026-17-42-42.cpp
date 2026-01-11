class Solution {
private:
    int m, n;
    int findMaxRect(vector<int>& heights) {
        // Get the maximum area in a histogram given its heights
        stack<int> st;
        st.push(-1);
        int maxArea = 0;

        for (int j = 0; j < n; ++j) {
            while (st.top() != -1 && heights[st.top()] >= heights[j]) {
            int height = heights[st.top()]; st.pop();
            maxArea = max(maxArea, height * (j - st.top() - 1));
            }

            st.push(j);
        }

        while (st.top() != -1) {
            int height = heights[st.top()]; st.pop();
            maxArea = max(maxArea, height * (static_cast<int>(n - st.top() - 1)));
        }
        
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        this -> m = matrix.size(), this -> n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Update the state of this row's histogram using the last row's histogram
                // by keeping track of the number of consecutive ones.
                heights[j] = (matrix[i][j] == '1')? heights[j] + 1 : 0;
            }
            
            // Update ans with the maximum area from this row's histogram
            ans = max(ans, findMaxRect(heights));
        }

        return ans;
    }
};