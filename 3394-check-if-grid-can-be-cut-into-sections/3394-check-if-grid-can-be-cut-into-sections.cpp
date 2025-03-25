class Solution {
private:
    // Check if valid cuts can be made in a specific dimension
    bool checkCuts(vector<vector<int>>& rectangles, int dim){
        int countGap = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        sort(rectangles.begin(), rectangles.end(), [dim](vector<int>& a, vector<int>& b){return a[dim] < b[dim];});
        
        // Track the furthest ending coordinate so far
        int furthestEnd = rectangles[0][dim + 2];
        
        for (int i = 1; i < rectangles.size(); ++i){
            vector<int>& rect = rectangles[i];
            
            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) ++countGap;

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return countGap >= 2;
    }


public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try both horizontal and vertical cuts
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }
};