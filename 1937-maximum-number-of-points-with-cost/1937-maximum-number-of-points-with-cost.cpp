typedef long long ll;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<ll> prevRow(n);
        
        // Intiailize the first row
        for (int c = 0; c < n; ++c)
            prevRow[c] = points[0][c];
        
        // Process each row
        for (int r = 1; r < m; ++r){
            vector<ll> currRow(n), leftMax(n), rightMax(n);
            
            // Calculate left-to-right maximum
            leftMax[0] = prevRow[0];
            for (int c = 1; c < n; ++c)
                leftMax[c] = max(leftMax[c - 1] - 1, prevRow[c]);
            
            // Calculate right-to-left maximum
            rightMax.back() = prevRow.back();
            for (int c = n - 2; c >= 0; --c)
                rightMax[c] = max(rightMax[c + 1] - 1, prevRow[c]);
            
            // Calculate the current row's maximum points
            for (int c = 0; c < n; ++c)
                currRow[c] = points[r][c] + max(leftMax[c], rightMax[c]);
            
            // Update the previousRow for the next iteration
            prevRow = currRow;
        }
        
        // Find the maximum value in the last processed row
        return *max_element(prevRow.begin(), prevRow.end());
    }
};