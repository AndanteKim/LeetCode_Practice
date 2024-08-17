typedef long long ll;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points[0].size();
        vector<ll> currRow(n), prevRow(n);
        ll runningMax;
        
        for (auto& row : points){
            // RunningMax holds the maximum value generated in the previous
            // iteration of each loop
            runningMax = 0;
            
            // Left to right pass
            for (int col = 0; col < row.size(); ++col){
                runningMax = max(runningMax - 1, prevRow[col]);
                currRow[col] = runningMax;
            }
            
            runningMax = 0;
            // Right to left pass
            for (int col = n - 1; col >= 0; --col){
                runningMax = max(runningMax - 1, prevRow[col]);
                currRow[col] = max(currRow[col], runningMax) + row[col];
            }
            
            // Update previousRow for the next iteration
            prevRow = currRow;
        }
        
        return *max_element(prevRow.begin(), prevRow.end());
    }
};