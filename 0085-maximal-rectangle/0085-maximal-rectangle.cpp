class Solution {
private:
    int monotone(vector<int>& heights){
        int maxArea = 0;
        stack<int> st;
        st.push(-1);
        
        for (int i = 0; i < heights.size(); ++i){
            while (st.top() != -1 && heights[i] <= heights[st.top()]){
                int height = heights[st.top()]; st.pop();
                maxArea = max(maxArea, height * (i - st.top() - 1));
            }
            st.push(i);
        }
        
        while (st.top() != -1){
            int height = heights[st.top()]; st.pop();
            maxArea = max(maxArea, height * ((int)heights.size() - st.top() - 1));
        }
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n);
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                // Update the state of this rows histogram using the last row's histogram
                // by keeping track of the number of consecutive ones
                dp[j] = (matrix[i][j] == '1')? ++dp[j] : 0;
            }
            // Update maxArea with the maximum area from the row's histogram
            maxArea = max(maxArea, monotone(dp));
        }
        
        return maxArea;
    }
};