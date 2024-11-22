class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Map to store frequency of each pattern
        unordered_map<string, int> patternFreq;
        
        for (const auto& currRow : matrix){
            string rowPattern = "";
            
            // Convert row to pattern relative to its first element
            for (int e : currRow){
                // 'T' if current element matches first element, 'F' otherwise
                if (e == currRow[0])
                    rowPattern.push_back('T');
                else
                    rowPattern.push_back('F');
            }
            
            // Convert pattern to string and update its frequency in map
            ++patternFreq[rowPattern];
        }
        
        // Find the pattern with maximum frequency
        int maxFreq = 0;
        for (const auto& [_, freq] : patternFreq)
            maxFreq = max(maxFreq, freq);
        
        return maxFreq;
    }
};