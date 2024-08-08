class Solution {
private:
    int m, n;
    
    int countPatternsFromNumber(int currNum, int currLen, vector<vector<int>>& jump, vector<bool>& visited){
        // Base case: If current pattern length exceeds max length, stop exploring
        if (currLen > n)
            return 0;
        
        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currLen >= m)
            ++validPatterns;
        
        visited[currNum] = true;
        
        // Explore all possible next numbers
        for (int nextNum = 1; nextNum < 10; ++nextNum){
            int jumpOverNum = jump[currNum][nextNum];
            
            // Check if the next number is unvisited and either:
            // 1. There's no number to jump over, or
            // 2. The number to jump over has been visited
            if (!visited[nextNum] && (jumpOverNum == 0 || visited[jumpOverNum]))
                validPatterns += countPatternsFromNumber(nextNum, currLen + 1, jump, visited);
        }
        
        // Backtrack: unmark the current number before returning
        visited[currNum] = false;
        return validPatterns;
    }
    
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> jump(10, vector<int>(10));
        int ans = 0;
        this -> m = m, this -> n = n;
        
        // Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;
        
        vector<bool> visited(10);
        // Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        ans += countPatternsFromNumber(1, 1, jump, visited) * 4;
        
        // Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        ans += countPatternsFromNumber(2, 1, jump, visited) * 4;
        
        // Count patterns starting from center number (5)
        ans += countPatternsFromNumber(5, 1, jump, visited);
        
        return ans;
    }
};